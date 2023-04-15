#pragma once

#include <list>
#include <Hedgehog/Base/System/hhAllocator.h>

namespace Hedgehog
{
    template<typename T, typename Allocator = Base::TAllocator<T>>
    class list
    {
    protected:
        struct SNode
        {
            using allocator_type = typename std::allocator_traits<Allocator>::template rebind_alloc<SNode>;

            SNode* pNext;
            SNode* pPrev;
            T Value;
        };

        typename SNode::allocator_type m_Alloc;
        SNode* m_pHead;
        size_t m_Count;

        void MakeHead()
        {
            m_pHead = m_Alloc.allocate(1);
            m_pHead->pNext = m_pHead;
            m_pHead->pPrev = m_pHead;
        }

        template<class... Args>
        SNode* Emplace(SNode* in_pNode, Args&&... args)
        {
            SNode* in_pNewNode = m_Alloc.allocate(1);

            in_pNewNode->pNext = in_pNode;
            in_pNewNode->pPrev = in_pNode->pPrev;
            new (&in_pNewNode->Value) T(std::forward<Args>(args)...);

            in_pNode->pPrev->pNext = in_pNewNode;
            in_pNode->pPrev = in_pNewNode;

            return in_pNewNode;
        }

    public:
        using value_type = T;
        using allocator_type = Allocator;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = typename std::allocator_traits<Allocator>::pointer;
        using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;

        class iterator
        {
        public:
            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using reference = T&;
            using pointer = T*;
            using iterator_category = std::bidirectional_iterator_tag;

            iterator(SNode* pNode) : m_pNode(pNode) {}

            reference operator*() const { return m_pNode->Value; }
            pointer operator->() const { return &m_pNode->Value; }

            iterator& operator++()
            {
                m_pNode = m_pNode->pNext;
                return *this;
            }

            iterator operator++(int)
            {
                iterator temp(*this);
                ++(*this);
                return temp;
            }

            iterator& operator--()
            {
                m_pNode = m_pNode->pPrev;
                return *this;
            }

            iterator operator--(int)
            {
                iterator temp(*this);
                --(*this);
                return temp;
            }

            friend bool operator==(const iterator& lhs, const iterator& rhs)
            {
                return lhs.m_pNode == rhs.m_pNode;
            }

            friend bool operator!=(const iterator& lhs, const iterator& rhs)
            {
                return !(lhs == rhs);
            }

        private:
            SNode* m_pNode;
            friend class list;
        };

        class const_iterator
        {
        public:
            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using reference = const T&;
            using pointer = const T*;
            using iterator_category = std::bidirectional_iterator_tag;

            const_iterator(SNode* pNode) : m_pNode(pNode) {}
            const_iterator(const iterator& iterator) : m_pNode(iterator.m_pNode) {}

            reference operator*() const { return m_pNode->Value; }
            pointer operator->() const { return &m_pNode->Value; }

            const_iterator& operator++()
            {
                m_pNode = m_pNode->pNext;
                return *this;
            }

            const_iterator operator++(int)
            {
                const_iterator temp(*this);
                ++(*this);
                return temp;
            }

            const_iterator& operator--()
            {
                m_pNode = m_pNode->pPrev;
                return *this;
            }

            const_iterator operator--(int)
            {
                const_iterator temp(*this);
                --(*this);
                return temp;
            }

            friend bool operator==(const const_iterator& lhs, const const_iterator& rhs)
            {
                return lhs.m_pNode == rhs.m_pNode;
            }

            friend bool operator!=(const const_iterator& lhs, const const_iterator& rhs)
            {
                return !(lhs == rhs);
            }

        private:
            SNode* m_pNode;
            friend class list;
        };

        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;

        list()
            : m_Alloc(), m_Count()
        {
            MakeHead();
        }

        explicit list(const Allocator& alloc)
            : m_Alloc(alloc), m_Count()
        {
            MakeHead();
        }

        list(size_type count, const T& value, const Allocator& alloc = Allocator())
            : m_Alloc(alloc), m_Count(count)
        {
            MakeHead();

            while (count != 0)
            {
                Emplace(m_pHead, value);
                --count;
            }
        }

        explicit list(size_type count, const Allocator& alloc = Allocator())
            : list(count, T{}, alloc)
        {
        }

        template<class InputIt>
        list(InputIt first, InputIt last, const Allocator& alloc = Allocator())
            : m_Alloc(alloc), m_Count()
        {
            MakeHead();

            for (auto it = first; it != last; ++it)
            {
                Emplace(m_pHead, (*it));
                ++m_Count;
            }
        }

        list(const list& other)
            : list(other, other.m_Alloc)
        {
        }

        list(const list& other, const Allocator& alloc)
            : m_Alloc(alloc), m_Count(other.m_Count)
        {
            MakeHead();

            for (SNode* pIt = other.m_pHead->pNext; pIt != other.m_pHead->pPrev; pIt = pIt->pNext)
                Emplace(m_pHead, pIt->Value);
        }

        list(list&& other)
            : m_Alloc(std::move(other.m_Alloc))
        {
            m_pHead = other.m_pHead;
            m_Count = other.m_Count;

            other.MakeHead();
            other.m_Count = 0;
        }

        list(list&& other, const Allocator& alloc)
            : m_Alloc(alloc)
        {
            m_pHead = other.m_pHead;
            m_Count = other.m_Count;

            other.MakeHead();
            other.m_Count = 0;
        }

        list(std::initializer_list<T> init, const Allocator& alloc = Allocator())
            : list(init.begin(), init.end(), alloc)
        {
        }

        ~list()
        {
            for (SNode* pIt = m_pHead->pNext; pIt != m_pHead->pPrev; pIt = pIt->pNext)
            {
                pIt->Value.~T();
                m_Alloc.deallocate(pIt, 1);
            }

            m_Alloc.deallocate(m_pHead, 1);
        }

        list& operator=(const list& other)
        {
            SNode* pThisNode = m_pHead->pNext;
            SNode* pOtherNode = other.m_pHead->pNext;

            while (pThisNode != m_pHead && pOtherNode != other.m_pHead)
            {
                pThisNode->Value = pOtherNode->Value;

                pThisNode = pThisNode->pNext;
                pOtherNode = pOtherNode->pNext;
            }

            pThisNode->pPrev->pNext = m_pHead;
            m_pHead->pPrev = pThisNode->pPrev;

            while (pThisNode != m_pHead)
            {
                SNode* pNextNode = pThisNode->pNext;

                pThisNode->Value.~T();
                m_Alloc.deallocate(pThisNode, 1);

                pThisNode = pNextNode;
            }

            while (pOtherNode != other.m_pHead)
            {
                Emplace(m_pHead, pOtherNode->Value);
                pOtherNode = pOtherNode->pNext;
            }

            m_Count = other.m_Count;

            return *this;
        }

        list& operator=(list&& other)
        {
            clear();

            std::swap(m_pHead, other.m_pHead);
            std::swap(m_Count, other.m_Count);

            return *this;
        }

        list& operator=(std::initializer_list<T> ilist)
        {
            assign(ilist.begin(), ilist.end());
            return *this;
        }

        void assign(size_type count, const T& value)
        {
            m_Count = count;

            SNode* pNode = m_pHead->pNext;

            while (pNode != m_pHead && count != 0)
            {
                pNode->Value = value;
                pNode = pNode->pNext;
                --count;
            }

            pNode->pPrev->pNext = m_pHead;
            m_pHead->pPrev = pNode->pPrev;

            while (pNode != m_pHead)
            {
                SNode* pNextNode = pNode->pNext;

                pNode->Value.~T();
                m_Alloc.deallocate(pNode, 1);

                pNode = pNextNode;
            }

            while (count != 0)
            {
                Emplace(m_pHead, value);
                --count;
            }
        }

        template<class InputIt>
        void assign(InputIt first, InputIt last)
        {
            m_Count = 0;

            SNode* pNode = m_pHead->pNext;
            auto cur = first;

            while (pNode != m_pHead && cur != last)
            {
                pNode->Value = (*cur);

                pNode = pNode->pNext;
                ++cur;

                ++m_Count;
            }

            pNode->pPrev->pNext = m_pHead;
            m_pHead->pPrev = pNode->pPrev;

            while (pNode != m_pHead)
            {
                SNode* pNextNode = pNode->pNext;

                pNode->Value.~T();
                m_Alloc.deallocate(pNode, 1);

                pNode = pNextNode;
            }

            while (cur != last)
            {
                Emplace(m_pHead, *cur);
                ++cur;
                ++m_Count;
            }
        }

        void assign(std::initializer_list<T> ilist)
        {
            assign(ilist.begin(), ilist.end());
        }

        allocator_type get_allocator() const
        {
            return m_Alloc;
        }

        reference front()
        {
            return m_pHead->pNext->Value;
        }

        const_reference front() const
        {
            return m_pHead->pNext->Value;
        }

        reference back()
        {
            return m_pHead->pPrev->Value;
        }

        const_reference back() const
        {
            return m_pHead->pPrev->Value;
        }

        iterator begin()
        {
            return iterator(m_pHead->pNext);
        }

        const_iterator begin() const
        {
            return const_iterator(m_pHead->pNext);
        }

        const_iterator cbegin() const
        {
            return const_iterator(m_pHead->pNext);
        }

        iterator end()
        {
            return iterator(m_pHead);
        }

        const_iterator end() const
        {
            return const_iterator(m_pHead);
        }

        const_iterator cend() const
        {
            return const_iterator(m_pHead);
        }

        reverse_iterator rbegin()
        {
            return reverse_iterator(end());
        }

        const_reverse_iterator rbegin() const
        {
            return const_reverse_iterator(end());
        }

        const_reverse_iterator crbegin() const
        {
            return const_reverse_iterator(cend());
        }

        reverse_iterator rend()
        {
            return reverse_iterator(begin());
        }

        const_reverse_iterator rend() const
        {
            return const_reverse_iterator(begin());
        }

        const_reverse_iterator crend() const
        {
            return const_reverse_iterator(cbegin());
        }

        bool empty() const
        {
            return m_Count == 0;
        }

        size_type size() const
        {
            return m_Count;
        }

        size_type max_size() const
        {
            return ~0u;
        }

        void clear()
        {
            for (SNode* pIt = m_pHead->pNext; pIt != m_pHead->pPrev; pIt = pIt->pNext)
            {
                pIt->Value.~T();
                m_Alloc.deallocate(pIt, 1);
            }

            m_pHead->pPrev = m_pHead;
            m_pHead->pNext = m_pHead;
            m_Count = 0;
        }

        iterator insert(const_iterator pos, const T& value)
        {
            ++m_Count;
            return iterator(Emplace(pos.m_pNode, value));
        }

        iterator insert(const_iterator pos, T&& value)
        {
            ++m_Count;
            return iterator(Emplace(pos.m_pNode, std::move(value)));
        }

        iterator insert(const_iterator pos, size_type count, const T& value)
        {
            if (count != 0)
            {
                m_Count += count;

                SNode* pNode = Emplace(pos.m_pNode, value);
                --count;

                SNode* pResult = pNode;

                while (count != 0)
                {
                    pNode = Emplace(pNode->pNext, value);
                    --count;
                }

                return iterator(pResult);
            }
            else
            {
                return iterator(pos.m_pNode);
            }
        }

        template<class InputIt>
        iterator insert(const_iterator pos, InputIt first, InputIt last)
        {
            if (first != last)
            {
                auto cur = first;

                SNode* pNode = Emplace(pos.m_pNode, *cur);
                ++cur;

                SNode* pResult = pNode;

                while (cur != last)
                {
                    pNode = Emplace(pNode->pNext, *cur);
                    ++cur;
                    ++m_Count;
                }

                return iterator(pResult);
            }
            else
            {
                return iterator(pos.m_pNode);
            }
        }

        iterator insert(const_iterator pos, std::initializer_list<T> ilist)
        {
            return insert(pos, ilist.begin(), ilist.end());
        }

        template<class... Args>
        iterator emplace(const_iterator pos, Args&&... args)
        {
            ++m_Count;
            return iterator(Emplace(pos.m_pNode, std::forward<Args>(args)...));
        }

        iterator erase(const_iterator pos)
        {
            pos.m_pNode->pPrev->pNext = pos.m_pNode->pNext;
            pos.m_pNode->pNext->pPrev = pos.m_pNode->pPrev;

            SNode* pNext = pos.m_pNode->pNext;

            pos.m_pNode->Value.~T();
            m_Alloc.deallocate(pos.m_pNode, 1);

            --m_Count;

            return iterator(pNext);
        }

        iterator erase(const_iterator first, const_iterator last)
        {
            if (first != last)
            {
                first.m_pNode->pPrev->pNext = last.m_pNode;
                last.m_pNode->pPrev = first.m_pNode->pPrev;

                SNode* pNode = first.m_pNode;
                while (pNode != last.m_pNode)
                {
                    SNode* pNext = pNode->pNext;
                    pNode->Value.~T();
                    m_Alloc.deallocate(pNode, 1);
                    pNode = pNext;
                    --m_Count;
                }
            }

            return iterator(last.m_pNode);
        }

        void push_back(const T& value)
        {
            ++m_Count;
            Emplace(m_pHead, value);
        }

        void push_back(T&& value)
        {
            ++m_Count;
            Emplace(m_pHead, std::move(value));
        }

        template<class... Args>
        reference emplace_back(Args&&... args)
        {
            ++m_Count;
            return Emplace(m_pHead, std::forward<Args>(args)...)->Value;
        }

        void pop_back()
        {
            SNode* pPrev = m_pHead->pPrev->pPrev;

            m_pHead->pPrev->Value.~T();
            m_Alloc.deallocate(m_pHead->pPrev, 1);

            pPrev->pNext = m_pHead;
            m_pHead->pPrev = pPrev;

            --m_Count;
        }

        void push_front(const T& value)
        {
            ++m_Count;
            Emplace(m_pHead->pNext, value);
        }

        void push_front(T&& value)
        {
            ++m_Count;
            Emplace(m_pHead->pNext, std::move(value));
        }

        template<class... Args>
        reference emplace_front(Args&&... args)
        {
            ++m_Count;
            return Emplace(m_pHead->pNext, std::forward<Args>(args)...)->Value;
        }

        void pop_front()
        {
            SNode* pNext = m_pHead->pNext->pNext;

            m_pHead->pNext->Value.~T();
            m_Alloc.deallocate(m_pHead->pNext, 1);

            pNext->pPrev = m_pHead;
            m_pHead->pNext = pNext;

            --m_Count;
        }

        void resize(size_type count)
        {
            resize(count, T{});
        }

        void resize(size_type count, const value_type& value)
        {
            size_type currentSize = size();
            if (count < currentSize)
            {
                for (size_type i = 0; i < currentSize - count; ++i)
                    pop_back();
            }
            else if (count > currentSize)
            {
                for (size_type i = 0; i < count - currentSize; ++i)
                    push_back(value);
            }
        }

        void swap(list& other)
        {
            std::swap(m_Alloc, other.m_Alloc);
            std::swap(m_pHead, other.m_pHead);
            std::swap(m_Count, other.m_Count);
        }
    };

    template<class T, class Alloc>
    inline bool operator==(const std::list<T, Alloc>& lhs, const std::list<T, Alloc>& rhs)
    {
        if (lhs.size() != rhs.size())
            return false;

        auto it0 = lhs.begin();
        auto it1 = rhs.begin();

        while (it0 != lhs.end() && it1 != rhs.end())
        {
            if ((*it0) != (*it1))
                return false;

            ++it0;
            ++it1;
        }

        return true;
    }

    BB_ASSERT_SIZEOF(list<int>, 0xC);
}

namespace hh = Hedgehog;