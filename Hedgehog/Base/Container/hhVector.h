#pragma once

#include <Hedgehog/Base/System/hhAllocator.h>

namespace Hedgehog
{
    template<typename T, typename Allocator = Hedgehog::Base::TAllocator<T>>
    class vector
    {
    protected:
        Allocator m_Alloc;
        T* m_pFirst;
        T* m_pLast;
        T* m_pEnd;

        void ReserveUnchecked(size_t in_NewCapacity)
        {
            T* alloc = m_Alloc.allocate(in_NewCapacity);
            std::uninitialized_move(m_pFirst, m_pLast, alloc);

            std::destroy(m_pFirst, m_pLast);
            m_Alloc.deallocate(m_pFirst, m_pEnd - m_pFirst);

            m_pLast = alloc + (m_pLast - m_pFirst);
            m_pFirst = alloc;
            m_pEnd = alloc + in_NewCapacity;
        }

        void ReserveOne()
        {
            if (m_pLast == m_pEnd)
                ReserveUnchecked(m_pFirst != m_pLast ? (m_pEnd - m_pFirst) * 2 : 1);
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
            using iterator_category = std::random_access_iterator_tag;
            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using pointer = T*;
            using reference = T&;

            iterator() : m_pPtr(nullptr) {}
            iterator(T* p) : m_pPtr(p) {}

            reference operator*() const { return *m_pPtr; }
            pointer operator->() const { return m_pPtr; }

            iterator& operator++() { ++m_pPtr; return *this; }
            iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }

            iterator& operator--() { --m_pPtr; return *this; }
            iterator operator--(int) { iterator tmp = *this; --(*this); return tmp; }

            iterator& operator+=(difference_type n) { m_pPtr += n; return *this; }
            iterator operator+(difference_type n) const { iterator tmp = *this; return tmp += n; }
            friend iterator operator+(difference_type n, iterator it) { return it + n; }

            iterator& operator-=(difference_type n) { return *this += -n; }
            iterator operator-(difference_type n) const { iterator tmp = *this; return tmp -= n; }
            difference_type operator-(const iterator& other) const { return m_pPtr - other.m_pPtr; }

            reference operator[](difference_type n) const { return *(*this + n); }

            bool operator==(const iterator& other) const { return m_pPtr == other.m_pPtr; }
            bool operator!=(const iterator& other) const { return !(*this == other); }
            bool operator<(const iterator& other) const { return m_pPtr < other.m_pPtr; }
            bool operator<=(const iterator& other) const { return !(other < *this); }
            bool operator>(const iterator& other) const { return other < *this; }
            bool operator>=(const iterator& other) const { return !(*this < other); }

        private:
            T* m_pPtr;

            friend class vector;
            friend class const_iterator;
        };

        class const_iterator
        {
        public:
            using iterator_category = std::random_access_iterator_tag;
            using value_type = T;
            using difference_type = std::ptrdiff_t;
            using pointer = const T*;
            using reference = const T&;

            const_iterator() : m_pPtr(nullptr) {}
            const_iterator(T* p) : m_pPtr(p) {}
            const_iterator(const iterator& other) : m_pPtr(other.m_pPtr) {}

            reference operator*() const { return *m_pPtr; }
            pointer operator->() const { return m_pPtr; }

            const_iterator& operator++() { ++m_pPtr; return *this; }
            const_iterator operator++(int) { const_iterator tmp = *this; ++(*this); return tmp; }

            const_iterator& operator--() { --m_pPtr; return *this; }
            const_iterator operator--(int) { const_iterator tmp = *this; --(*this); return tmp; }

            const_iterator& operator+=(difference_type n) { m_pPtr += n; return *this; }
            const_iterator operator+(difference_type n) const { const_iterator tmp = *this; return tmp += n; }
            friend const_iterator operator+(difference_type n, const_iterator it) { return it + n; }

            const_iterator& operator-=(difference_type n) { return *this += -n; }
            const_iterator operator-(difference_type n) const { const_iterator tmp = *this; return tmp -= n; }
            difference_type operator-(const const_iterator& other) const { return m_pPtr - other.m_pPtr; }

            reference operator[](difference_type n) const { return *(*this + n); }

            bool operator==(const const_iterator& other) const { return m_pPtr == other.m_pPtr; }
            bool operator!=(const const_iterator& other) const { return !(*this == other); }
            bool operator<(const const_iterator& other) const { return m_pPtr < other.m_pPtr; }
            bool operator<=(const const_iterator& other) const { return !(other < *this); }
            bool operator>(const const_iterator& other) const { return other < *this; }
            bool operator>=(const const_iterator& other) const { return !(*this < other); }

        private:
            T* m_pPtr;
            friend class vector;
        };

        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;

        vector() 
            : m_Alloc()
            , m_pFirst()
            , m_pLast()
            , m_pEnd()
        {
        }

        explicit vector(const Allocator& alloc) 
            : m_Alloc(alloc)
            , m_pFirst()
            , m_pLast()
            , m_pEnd()
        {
        }

        vector(size_type count, const T& value, const Allocator& alloc = Allocator())
            : m_Alloc(alloc)
        {
            if (count != 0)
            {
                m_pFirst = m_Alloc.allocate(count);
                m_pLast = m_pFirst + count;
                m_pEnd = m_pLast;
                std::uninitialized_fill(m_pFirst, m_pLast, value);
            }
            else
            {
                m_pFirst = nullptr;
                m_pLast = nullptr;
                m_pEnd = nullptr;
            }
        }

        explicit vector(size_type count, const Allocator& alloc = Allocator())
            : m_Alloc(alloc)
        {
            if (count != 0)
            {
                m_pFirst = m_Alloc.allocate(count);
                m_pLast = m_pFirst + count;
                m_pEnd = m_pLast;
                std::uninitialized_default_construct(m_pFirst, m_pLast);
            }
            else
            {
                m_pFirst = nullptr;
                m_pLast = nullptr;
                m_pEnd = nullptr;
            }
        }

        template<class InputIt>
        vector(InputIt first, InputIt last, const Allocator& alloc = Allocator())
            : m_Alloc(alloc)
        {
            auto count = std::distance(first, last);

            if (count != 0)
            {
                m_pFirst = m_Alloc.allocate(count);
                m_pLast = m_pFirst + count;
                m_pEnd = m_pLast;
                std::uninitialized_copy(first, last, m_pFirst);
            }
            else
            {
                m_pFirst = nullptr;
                m_pLast = nullptr;
                m_pEnd = nullptr;
            }
        }

        vector(const vector& other)
            : m_Alloc(other.m_Alloc)
        {
            if (!other.empty())
            {
                m_pFirst = m_Alloc.allocate(other.size());
                m_pLast = m_pFirst + other.size();
                m_pEnd = m_pLast;
                std::uninitialized_copy(other.m_pFirst, other.m_pLast, m_pFirst);
            }
            else
            {
                m_pFirst = nullptr;
                m_pLast = nullptr;
                m_pEnd = nullptr;
            }
        }

        vector(const vector& other, const Allocator& alloc)
            : m_Alloc(alloc)
        {
            if (!other.empty())
            {
                m_pFirst = m_Alloc.allocate(other.size());
                m_pLast = m_pFirst + other.size();
                m_pEnd = m_pLast;
                std::uninitialized_copy(other.m_pFirst, other.m_pLast, m_pFirst);
            }
            else
            {
                m_pFirst = nullptr;
                m_pLast = nullptr;
                m_pEnd = nullptr;
            }
        }

        vector(vector&& other)
            : m_Alloc(std::move(other.m_Alloc))
        {
            m_pFirst = other.m_pFirst;
            m_pLast = other.m_pLast;
            m_pEnd = other.m_pEnd;
            other.m_pFirst = nullptr;
            other.m_pLast = nullptr;
            other.m_pEnd = nullptr;
        }

        vector(vector&& other, const Allocator& alloc)
            : m_Alloc(alloc)
        {
            m_pFirst = other.m_pFirst;
            m_pLast = other.m_pLast;
            m_pEnd = other.m_pEnd;
            other.m_pFirst = nullptr;
            other.m_pLast = nullptr;
            other.m_pEnd = nullptr;
        }

        vector(std::initializer_list<T> init, const Allocator& alloc = Allocator())
            : m_Alloc(alloc)
        {
            if (init.size() != 0)
            {
                m_pFirst = m_Alloc.allocate(init.size());
                m_pLast = m_pFirst + init.size();
                m_pEnd = m_pLast;
                std::uninitialized_copy(init.begin(), init.end(), m_pFirst);
            }
            else
            {
                m_pFirst = nullptr;
                m_pLast = nullptr;
                m_pEnd = nullptr;
            }
        }

        ~vector()
        {
            std::destroy(m_pFirst, m_pLast);
            m_Alloc.deallocate(m_pFirst, m_pEnd - m_pFirst);

            m_pFirst = nullptr;
            m_pLast = nullptr;
            m_pEnd = nullptr;
        }

        vector& operator=(const vector& other)
        {
            if (this != &other)
            {
                clear();

                if (!other.empty())
                {
                    reserve(other.size());
                    m_pLast += other.size();
                    std::uninitialized_copy(other.m_pFirst, other.m_pLast, m_pFirst);
                }
            }
            return *this;
        }

        vector& operator=(vector&& other)
        {
            if (this != &other)
            {
                m_pFirst = other.m_pFirst;
                m_pLast = other.m_pLast;
                m_pEnd = other.m_pEnd;
                other.m_pFirst = nullptr;
                other.m_pLast = nullptr;
                other.m_pEnd = nullptr;
            }
            return *this;
        }

        vector& operator=(std::initializer_list<T> ilist)
        {
            assign(ilist);
            return *this;
        }

        void assign(size_type count, const T& value)
        {
            clear();

            if (count != 0)
            {
                reserve(count);
                m_pLast += count;
                std::uninitialized_fill(m_pFirst, m_pLast, value);
            }
        }

        template<class InputIt>
        void assign(InputIt first, InputIt last)
        {
            clear();

            auto count = std::distance(first, last);
            if (count != 0)
            {
                reserve(count);
                std::uninitialized_copy(first, last, m_pFirst);
                m_pLast += count;
            }
        }

        void assign(std::initializer_list<T> ilist)
        {
            clear();

            if (ilist.size() != 0)
            {
                reserve(ilist.size());
                std::uninitialized_copy(ilist.begin(), ilist.end(), m_pFirst);
                m_pLast += ilist.size();
            }
        }

        allocator_type get_allocator() const
        {
            return m_Alloc;
        }

        reference at(size_type pos)
        {
            return m_pFirst[pos];
        }

        const_reference at(size_type pos) const
        {
            return m_pFirst[pos];
        }

        reference operator[](size_type pos)
        {
            return m_pFirst[pos];
        }

        const_reference operator[](size_type pos) const
        {
            return m_pFirst[pos];
        }

        reference front()
        {
            return m_pFirst[0];
        }

        const_reference front() const
        {
            return m_pFirst[0];
        }

        reference back()
        {
            return m_pLast[-1];
        }

        const_reference back() const
        {
            return m_pLast[-1];
        }

        T* data()
        {
            return m_pFirst;
        }

        const T* data() const
        {
            return m_pFirst;
        }

        iterator begin()
        {
            return iterator(m_pFirst);
        }

        const_iterator begin() const
        {
            return const_iterator(m_pFirst);
        }

        const_iterator cbegin() const
        {
            return const_iterator(m_pFirst);
        }

        iterator end()
        {
            return iterator(m_pLast);
        }

        const_iterator end() const
        {
            return const_iterator(m_pLast);
        }

        const_iterator cend() const
        {
            return const_iterator(m_pLast);
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
            return m_pFirst == m_pLast;
        }

        size_type size() const
        {
            return m_pLast - m_pFirst;
        }

        size_type max_size() const
        {
            return ~0u;
        }

        void reserve(size_type new_cap)
        {
            if (m_pFirst + new_cap > m_pEnd)
                ReserveUnchecked(new_cap);
        }

        size_type capacity() const
        {
            return m_pEnd - m_pFirst;
        }

        void shrink_to_fit()
        {
            if (m_pFirst != m_pLast)
            {
                ReserveUnchecked(m_pLast - m_pFirst);
            }
            else
            {
                m_Alloc.deallocate(m_pFirst, m_pEnd - m_pFirst);
                m_pFirst = nullptr;
                m_pLast = nullptr;
                m_pEnd = nullptr;
            }
        }

        void clear()
        {
            std::destroy(m_pFirst, m_pLast);
            m_pLast = m_pFirst;
        }

        iterator insert(const_iterator pos, const T& value)
        {
            return emplace(pos, value);
        }

        iterator insert(const_iterator pos, T&& value)
        {
            return emplace(pos, std::move(value));
        }

        template<class... Args>
        iterator emplace(const_iterator pos, Args&&... args)
        {
            auto offset = pos - begin();
            if (m_pLast == m_pEnd)
            {
                size_t capacity = m_pFirst != m_pLast ? (m_pEnd - m_pFirst) * 2 : 1;

                T* alloc = m_Alloc.allocate(capacity);
                std::uninitialized_move(m_pFirst, m_pFirst + offset, alloc);
                new (alloc + offset) T(std::forward<Args>(args)...);
                std::uninitialized_move(m_pFirst + offset, m_pLast, alloc + offset + 1);

                std::destroy(m_pFirst, m_pLast);
                m_Alloc.deallocate(m_pFirst, m_pEnd - m_pFirst);

                m_pLast = alloc + (m_pLast - m_pFirst) + 1;
                m_pFirst = alloc;
                m_pEnd = alloc + capacity;
            }
            else
            {
                new (m_pLast) T();
                std::move_backward(m_pFirst + offset, m_pLast, m_pLast + 1);
                new (m_pFirst + offset) T(std::forward<Args>(args)...);
                ++m_pLast;
            }
            return iterator(m_pFirst + offset);
        }

        iterator erase(const_iterator pos)
        {
            std::move(pos.m_pPtr + 1, m_pLast, pos.m_pPtr);
            pop_back();

            return iterator(pos.m_pPtr);
        }

        iterator erase(const_iterator first, const_iterator last)
        {
            std::move(last.m_pPtr, m_pLast, first.m_pPtr);

            T* pNewLast = m_pLast - (last.m_pPtr - first.m_pPtr);
            std::destroy(pNewLast, m_pLast);
            m_pLast = pNewLast;

            return iterator(first.m_pPtr);
        }

        void push_back(const T& value)
        {
            emplace_back(value);
        }

        void push_back(T&& value)
        {
            emplace_back(std::move(value));
        }

        template<class... Args>
        reference emplace_back(Args&&... args)
        {
            ReserveOne();
            new (m_pLast) T(std::forward<Args>(args)...);
            return *(m_pLast++);
        }

        void pop_back()
        {
            --m_pLast;
            m_pLast->~T();
        }

        void resize(size_type count)
        {
            resize(count, T{});
        }

        void resize(size_type count, const value_type& value)
        {
            if (m_pFirst + count < m_pLast)
            {
                std::destroy(m_pFirst + count, m_pLast);
            }
            else if (m_pFirst + count > m_pLast)
            {
                ReserveUnchecked(count);
                std::uninitialized_fill(m_pLast, m_pFirst + count, value);
            }
            m_pLast = m_pFirst + count;
        }

        void swap(vector& other)
        {
            std::swap(m_pFirst, other.m_pFirst);
            std::swap(m_pLast, other.m_pLast);
            std::swap(m_pEnd, other.m_pEnd);
        }
    };

    BB_ASSERT_SIZEOF(vector<int>, 0x10);
}

namespace hh = Hedgehog;