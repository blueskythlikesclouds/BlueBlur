#pragma once

#include <Hedgehog/Base/System/hhAllocator.h>

namespace Hedgehog
{
    template<
        class Key, 
        class T, 
        class Compare = std::less<Key>, 
        class Allocator = Base::TAllocator<std::pair<const Key, T>>>
    class map
    {
    protected:
        enum EColor
        {
            eColor_Red,
            eColor_Black
        };

        struct SNode
        {
            using allocator_type = typename std::allocator_traits<Allocator>::template rebind_alloc<SNode>;

            SNode* pLeft;
            SNode* pParent;
            SNode* pRight;
            std::pair<const Key, T> Value;
            uint8_t Color;
            bool IsNil;
        };

        Compare m_Comp;
        typename SNode::allocator_type m_Alloc;
        SNode* m_pHead;
        size_t m_Count;

        void MakeHead()
        {
            m_pHead = m_Alloc.allocate(1);
            m_pHead->pLeft = m_pHead;
            m_pHead->pParent = m_pHead;
            m_pHead->pRight = m_pHead;
            m_pHead->Color = eColor_Black;
            m_pHead->IsNil = true;
        }

        struct SFindResult
        {
            SNode* pParent;
            bool IsRight;
            SNode* pBound;
        };

        bool LowerBoundDuplicate(const SNode* pBound, const Key& in_rKey) const
        {
            return !pBound->IsNil && !m_Comp(in_rKey, pBound->Value.first);
        }

        SFindResult FindLowerBound(const Key& in_rKey) const
        {
            SFindResult result{ m_pHead->pParent, true, m_pHead };
            SNode* pNode = result.pParent;

            while (!pNode->IsNil)
            {
                result.pParent = pNode;
                if (m_Comp(pNode->Value.first, in_rKey))
                {
                    result.IsRight = true;
                    pNode = pNode->pRight;
                }
                else
                {
                    result.IsRight = false;
                    result.pBound = pNode;
                    pNode = pNode->pLeft;
                }
            }

            return result;
        }

        SNode* Find(const Key& in_rKey) const
        {
            const SFindResult result = FindLowerBound(in_rKey);
            return LowerBoundDuplicate(result.pBound, in_rKey) ? result.pBound : m_pHead;
        }

        static SNode* Max(SNode* pNode)
        {
            while (!pNode->pRight->IsNil)
                pNode = pNode->pRight;

            return pNode;
        }

        static SNode* Min(SNode* pNode)
        {
            while (!pNode->pLeft->IsNil)
                pNode = pNode->pLeft;

            return pNode;
        }

        void RotateLeft(SNode* pWhere)
        {
            SNode* pNode = pWhere->pRight;
            pWhere->pRight = pNode->pLeft;

            if (!pNode->pLeft->IsNil)
                pNode->pLeft->pParent = pWhere;

            pNode->pParent = pWhere->pParent;

            if (pWhere == m_pHead->pParent)
                m_pHead->pParent = pNode;
            else if (pWhere == pWhere->pParent->pLeft)
                pWhere->pParent->pLeft = pNode;
            else
                pWhere->pParent->pRight = pNode;

            pNode->pLeft = pWhere;
            pWhere->pParent = pNode;
        }

        void RotateRight(SNode* pWhere)
        {
            SNode* pNode = pWhere->pLeft;
            pWhere->pLeft = pNode->pRight;

            if (!pNode->pRight->IsNil)
                pNode->pRight->pParent = pWhere;

            pNode->pParent = pWhere->pParent;

            if (pWhere == m_pHead->pParent)
                m_pHead->pParent = pNode;
            else if (pWhere == pWhere->pParent->pRight)
                pWhere->pParent->pRight = pNode;
            else
                pWhere->pParent->pLeft = pNode;

            pNode->pRight = pWhere;
            pWhere->pParent = pNode;
        }

        void DeleteRecursively(SNode* in_pNode)
        {
            while (!in_pNode->IsNil)
            {
                DeleteRecursively(in_pNode->pRight);

                SNode* pLeft = in_pNode->pLeft;

                in_pNode->Value.~value_type();
                m_Alloc.deallocate(in_pNode, 1);

                in_pNode = pLeft;
            }
        }

        SNode* Copy(SNode* pOtherNode)
        {
            if (pOtherNode->IsNil)
                return m_pHead;

            SNode* pNode = m_Alloc.allocate(1);
            new (&pNode->Value) value_type(pOtherNode->Value);

            pNode->pParent = m_pHead;
            pNode->Color = pOtherNode->Color;
            pNode->IsNil = pOtherNode->IsNil;

            pNode->pLeft = Copy(pOtherNode->pLeft);

            if (!pNode->pLeft->IsNil)
                pNode->pLeft->pParent = pNode;

            pNode->pRight = Copy(pOtherNode->pRight);

            if (!pNode->pRight->IsNil)
                pNode->pRight->pParent = pNode;

            return pNode;
        }

        void InsertFixup(SNode* in_pNode)
        {
            for (SNode* pNode = in_pNode; pNode->pParent->Color == eColor_Red;)
            {
                if (pNode->pParent == pNode->pParent->pParent->pLeft)
                {
                    SNode* pUncle = pNode->pParent->pParent->pRight;
                    if (pUncle->Color == eColor_Red)
                    {
                        pNode->pParent->Color = eColor_Black;
                        pUncle->Color = eColor_Black;
                        pNode->pParent->pParent->Color = eColor_Red;
                        pNode = pNode->pParent->pParent;
                    }
                    else
                    {
                        if (pNode == pNode->pParent->pRight)
                        {
                            pNode = pNode->pParent;
                            RotateLeft(pNode);
                        }

                        pNode->pParent->Color = eColor_Black;
                        pNode->pParent->pParent->Color = eColor_Red;
                        RotateRight(pNode->pParent->pParent);
                    }
                }
                else
                {
                    SNode* pUncle = pNode->pParent->pParent->pLeft;
                    if (pUncle->Color == eColor_Red)
                    {
                        pNode->pParent->Color = eColor_Black;
                        pUncle->Color = eColor_Black;
                        pNode->pParent->pParent->Color = eColor_Red;
                        pNode = pNode->pParent->pParent;
                    }
                    else
                    {
                        if (pNode == pNode->pParent->pLeft)
                        {
                            pNode = pNode->pParent;
                            RotateRight(pNode);
                        }

                        pNode->pParent->Color = eColor_Black;
                        pNode->pParent->pParent->Color = eColor_Red;
                        RotateLeft(pNode->pParent->pParent);
                    }
                }
            }

            m_pHead->pParent->Color = eColor_Black;
        }

    public:
        using key_type = Key;
        using mapped_type = T;
        using value_type = std::pair<const Key, T>;
        using size_type = std::size_t;
        using difference_type = std::ptrdiff_t;
        using key_compare = Compare;
        using allocator_type = Allocator;
        using reference = value_type&;
        using const_reference = const value_type&;
        using pointer = typename std::allocator_traits<Allocator>::pointer;
        using const_pointer = typename std::allocator_traits<Allocator>::const_pointer;

        class iterator
        {
        public:
            using iterator_category = std::bidirectional_iterator_tag;
            using value_type = std::pair<const Key, T>;
            using difference_type = std::ptrdiff_t;
            using pointer = value_type*;
            using reference = value_type&;

            iterator(const std::nullptr_t&) = delete;
            iterator(SNode* pNode) : m_pNode(pNode) {}

            reference operator*() const { return m_pNode->Value; }
            pointer operator->() const { return &m_pNode->Value; }

            iterator& operator++()
            {
                if (m_pNode->pRight->IsNil)
                {
                    SNode* pNode;
                    while (!(pNode = m_pNode->pParent)->IsNil && m_pNode == pNode->pRight)
                        m_pNode = pNode;

                    m_pNode = pNode;
                }
                else
                {
                    m_pNode = map::Min(m_pNode->pRight);
                }

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
                if (m_pNode->IsNil)
                {
                    m_pNode = m_pNode->pRight;
                }
                else if (m_pNode->pLeft->IsNil)
                {
                    SNode* pNode;
                    while (!(pNode = m_pNode->pParent)->IsNil && m_pNode == pNode->pLeft)
                        m_pNode = pNode;

                    if (!m_pNode->IsNil)
                        m_pNode = pNode;
                }
                else
                {
                    m_pNode = map::Max(m_pNode->pLeft);
                }

                return *this;
            }

            iterator operator--(int)
            {
                iterator temp(*this);
                --(*this);
                return temp;
            }

            bool operator==(const iterator& rhs) const { return m_pNode == rhs.m_pNode; }
            bool operator!=(const iterator& rhs) const { return !(*this == rhs); }

        private:
            SNode* m_pNode;
            friend class iterator;
            friend class map;
        };

        class const_iterator
        {
        public:
            using iterator_category = std::bidirectional_iterator_tag;
            using value_type = std::pair<const Key, T>;
            using difference_type = std::ptrdiff_t;
            using pointer = const value_type*;
            using reference = const value_type&;

            const_iterator(const std::nullptr_t&) = delete;
            const_iterator(SNode* pNode) : m_pNode(pNode) {}
            const_iterator(const iterator& iterator) : m_pNode(iterator.m_pNode) {}

            reference operator*() const { return m_pNode->Value; }
            pointer operator->() const { return &m_pNode->Value; }

            const_iterator& operator++()
            {
                if (m_pNode->pRight->IsNil)
                {
                    SNode* pNode;
                    while (!(pNode = m_pNode->pParent)->IsNil && m_pNode == pNode->pRight)
                        m_pNode = pNode;

                    m_pNode = pNode;
                }
                else
                {
                    m_pNode = map::Min(m_pNode->pRight);
                }

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
                if (m_pNode->IsNil)
                {
                    m_pNode = m_pNode->pRight;
                }
                else if (m_pNode->pLeft->IsNil)
                {
                    SNode* pNode;
                    while (!(pNode = m_pNode->pParent)->IsNil && m_pNode == pNode->pLeft)
                        m_pNode = pNode;

                    if (!m_pNode->IsNil)
                        m_pNode = pNode;
                }
                else
                {
                    m_pNode = map::Max(m_pNode->pLeft);
                }

                return *this;
            }

            const_iterator operator--(int)
            {
                const_iterator temp(*this);
                --(*this);
                return temp;
            }

            bool operator==(const const_iterator& rhs) const { return m_pNode == rhs.m_pNode; }
            bool operator!=(const const_iterator& rhs) const { return !(*this == rhs); }

        private:
            SNode* m_pNode;
            friend class map;
        };

        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;

    protected:
        SNode* Extract(const_iterator where)
        {
            SNode* pErasedNode = where.m_pNode;
            ++where;

            SNode* pFixNode;
            SNode* pFixNodeParent;
            SNode* pNode = pErasedNode;

            if (pNode->pLeft->IsNil)
            {
                pFixNode = pNode->pRight;
            }
            else if (pNode->pRight->IsNil)
            {
                pFixNode = pNode->pLeft;
            }
            else
            {
                pNode = where.m_pNode;
                pFixNode = pNode->pRight;
            }

            if (pNode == pErasedNode)
            {
                pFixNodeParent = pErasedNode->pParent;
                if (!pFixNode->IsNil)
                    pFixNode->pParent = pFixNodeParent;

                if (m_pHead->pParent == pErasedNode)
                    m_pHead->pParent = pFixNode;
                else if (pFixNodeParent->pLeft == pErasedNode)
                    pFixNodeParent->pLeft = pFixNode;
                else
                    pFixNodeParent->pRight = pFixNode;

                if (m_pHead->pLeft == pErasedNode)
                    m_pHead->pLeft = pFixNode->IsNil ? pFixNodeParent : Min(pFixNode);

                if (m_pHead->pRight == pErasedNode)
                    m_pHead->pRight = pFixNode->IsNil ? pFixNodeParent : Max(pFixNode);
            }
            else
            {
                pErasedNode->pLeft->pParent = pNode;
                pNode->pLeft = pErasedNode->pLeft;

                if (pNode == pErasedNode->pRight)
                {
                    pFixNodeParent = pNode;
                }
                else
                {
                    pFixNodeParent = pNode->pParent;
                    if (!pFixNode->IsNil)
                        pFixNode->pParent = pFixNodeParent;

                    pFixNodeParent->pLeft = pFixNode;
                    pNode->pRight = pErasedNode->pRight;
                    pErasedNode->pRight->pParent = pNode;
                }

                if (m_pHead->pParent == pErasedNode)
                    m_pHead->pParent = pNode;
                else if (pErasedNode->pParent->pLeft == pErasedNode)
                    pErasedNode->pParent->pLeft = pNode;
                else
                    pErasedNode->pParent->pRight = pNode;

                pNode->pParent = pErasedNode->pParent;
                std::swap(pNode->Color, pErasedNode->Color);
            }

            if (pErasedNode->Color == eColor_Black)
            {
                for (; pFixNode != m_pHead->pParent && pFixNode->Color == eColor_Black; pFixNodeParent = pFixNode->pParent)
                {
                    if (pFixNode == pFixNodeParent->pLeft)
                    {
                        pNode = pFixNodeParent->pRight;
                        if (pNode->Color == eColor_Red)
                        {
                            pNode->Color = eColor_Black;
                            pFixNodeParent->Color = eColor_Red;
                            RotateLeft(pFixNodeParent);
                            pNode = pFixNodeParent->pRight;
                        }

                        if (pNode->IsNil)
                        {
                            pFixNode = pFixNodeParent;
                        }
                        else if (pNode->pLeft->Color == eColor_Black
                            && pNode->pRight->Color == eColor_Black)
                        {
                            pNode->Color = eColor_Red;
                            pFixNode = pFixNodeParent;
                        }
                        else
                        {
                            if (pNode->pRight->Color == eColor_Black)
                            {
                                pNode->pLeft->Color = eColor_Black;
                                pNode->Color = eColor_Red;
                                RotateRight(pNode);
                                pNode = pFixNodeParent->pRight;
                            }

                            pNode->Color = pFixNodeParent->Color;
                            pFixNodeParent->Color = eColor_Black;
                            pNode->pRight->Color = eColor_Black;
                            RotateLeft(pFixNodeParent);
                            break;
                        }
                    }
                    else
                    {
                        pNode = pFixNodeParent->pLeft;
                        if (pNode->Color == eColor_Red)
                        {
                            pNode->Color = eColor_Black;
                            pFixNodeParent->Color = eColor_Red;
                            RotateRight(pFixNodeParent);
                            pNode = pFixNodeParent->pLeft;
                        }

                        if (pNode->IsNil)
                        {
                            pFixNode = pFixNodeParent;
                        }
                        else if (pNode->pRight->Color == eColor_Black
                            && pNode->pLeft->Color == eColor_Black)
                        {
                            pNode->Color = eColor_Red;
                            pFixNode = pFixNodeParent;
                        }
                        else
                        {
                            if (pNode->pLeft->Color == eColor_Black)
                            {
                                pNode->pRight->Color = eColor_Black;
                                pNode->Color = eColor_Red;
                                RotateLeft(pNode);
                                pNode = pFixNodeParent->pLeft;
                            }

                            pNode->Color = pFixNodeParent->Color;
                            pFixNodeParent->Color = eColor_Black;
                            pNode->pLeft->Color = eColor_Black;
                            RotateRight(pFixNodeParent);
                            break;
                        }
                    }
                }

                pFixNode->Color = eColor_Black;
            }

            if (0 < m_Count)
                --m_Count;

            return pErasedNode;
        }

        SNode* Erase(const_iterator iterator)
        {
            auto next = iterator;
            ++next;

            SNode* pNode = Extract(iterator.m_pNode);
            pNode->Value.~value_type();
            m_Alloc.deallocate(pNode, 1);

            return next.m_pNode;
        }

        SNode* Erase(const_iterator first, const_iterator last)
        {
            if (first == begin() && last.m_pNode->IsNil)
            {
                clear();
                return last.m_pNode;
            }

            while (first != last)
                Erase(first++);

            return last.m_pNode;
        }

    public:
        map()
            : m_Comp()
            , m_Alloc()
            , m_Count()
        {
            MakeHead();
        }

        explicit map(const Compare& comp, const Allocator& alloc = Allocator())
            : m_Comp(comp)
            , m_Alloc(alloc)
            , m_Count()
        {
            MakeHead();
        }

        explicit map(const Allocator& alloc)
            : m_Comp()
            , m_Alloc(alloc)
            , m_Count()
        {
            MakeHead();
        }

        template<class InputIt>
        map(InputIt first, InputIt last, const Compare& comp = Compare(), const Allocator& alloc = Allocator())
            : m_Comp(comp)
            , m_Alloc(alloc)
            , m_Count()
        {
            MakeHead();

            for (auto it = first; it != last; ++it)
                emplace(*it);
        }

        template<class InputIt>
        map(InputIt first, InputIt last, const Allocator& alloc)
            : m_Comp()
            , m_Alloc(alloc)
            , m_Count()
        {
            MakeHead();

            for (auto it = first; it != last; ++it)
                emplace(*it);
        }

        map(const map& other)
            : map(other, other.m_Alloc)
        {
            
        }

        map(const map& other, const Allocator& alloc)
            : m_Comp(other.m_Comp)
            , m_Alloc(alloc)
            , m_Count(other.m_Count)
        {
            MakeHead();

            m_pHead->pParent = Copy(other.m_pHead->pParent);

            if (!m_pHead->pParent->IsNil)
            {
                m_pHead->pLeft = Min(m_pHead->pParent);
                m_pHead->pRight = Max(m_pHead->pParent);
            }
        }

        map(map&& other)
            : map(std::move(other), std::move(other.m_Alloc))
        {
        }

        map(map&& other, const Allocator& alloc)
            : m_Comp(std::move(other.m_Comp))
            , m_Alloc(alloc)
            , m_pHead(other.m_pHead)
            , m_Count(other.m_Count)
        {
            other.MakeHead();
            other.m_Count = 0;
        }

        map(std::initializer_list<value_type> init, const Compare& comp = Compare(), const Allocator& alloc = Allocator())
            : map(init.begin(), init.end(), comp, alloc)
        {
        }

        map(std::initializer_list<value_type> init, const Allocator& alloc)
            : map(init, {}, alloc)
        {
        }

        ~map()
        {
            DeleteRecursively(m_pHead->pParent);
            m_Alloc.deallocate(m_pHead, 1);
        }

        map& operator=(const map& other)
        {
            if (this != &other)
            {
                clear();

                m_pHead->pParent = Copy(other.m_pHead->pParent);

                if (!m_pHead->pParent->IsNil)
                {
                    m_pHead->pLeft = Min(m_pHead->pParent);
                    m_pHead->pRight = Max(m_pHead->pParent);
                }

                m_Count = other.m_Count;
            }

            return *this;
        }

        map& operator=(map&& other)
        {
            if (this != &other)
            {
                clear();
                std::swap(m_pHead, other.m_pHead);
                std::swap(m_Count, other.m_Count);
            }

            return *this;
        }

        map& operator=(std::initializer_list<value_type> ilist)
        {
            clear();

            for (auto it = ilist.begin(); it != ilist.end(); ++it)
                emplace(*it);

            return *this;
        }

        allocator_type get_allocator() const
        {
            return m_Alloc;
        }

        T& at(const Key& key)
        {
            return Find(key)->Value.second;
        }

        const T& at(const Key& key) const
        {
            return Find(key)->Value.second;
        }

        T& operator[](const Key& key)
        {
            return emplace(key).first->second;
        }

        T& operator[](Key&& key)
        {
            return emplace(std::move(key), T{}).first->second;
        }

        iterator begin()
        {
            return iterator(m_pHead->pLeft);
        }

        const_iterator begin() const
        {
            return const_iterator(m_pHead->pLeft);
        }

        const_iterator cbegin() const
        {
            return const_iterator(m_pHead->pLeft);
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
            DeleteRecursively(m_pHead->pParent);

            m_pHead->pLeft = m_pHead;
            m_pHead->pParent = m_pHead;
            m_pHead->pRight = m_pHead;

            m_Count = 0;
        }

        std::pair<iterator, bool> insert(const value_type& value)
        {
            return emplace(value);
        }

        template<class P>
        std::pair<iterator, bool> insert(P&& value)
        {
            return emplace(std::forward<P>(value));
        }

        std::pair<iterator, bool> insert(value_type&& value)
        {
            return emplace(std::move(value));
        }

        template<class InputIt>
        void insert(InputIt first, InputIt last)
        {
            for (auto it = first; it != last; ++it)
                emplace(*it);
        }

        void insert(std::initializer_list<value_type> ilist)
        {
            insert(ilist.begin(), ilist.end());
        }

        template<class... Args>
        std::pair<iterator, bool> emplace(Args&&... args)
        {
            value_type value(std::forward<Args>(args)...);

            const SFindResult result = FindLowerBound(value.first);
            if (LowerBoundDuplicate(result.pBound, value.first))
                return std::make_pair(result.pBound, false);

            SNode* pNode = m_Alloc.allocate(1);
            pNode->pLeft = m_pHead;
            pNode->pParent = result.pParent;
            pNode->pRight = m_pHead;
            new (&pNode->Value) value_type(std::move(value));
            pNode->IsNil = false;

            if (result.pParent == m_pHead)
            {
                m_pHead->pLeft = pNode;
                m_pHead->pParent = pNode;
                m_pHead->pRight = pNode;
                pNode->Color = eColor_Black;
            }
            else
            {
                if (result.IsRight)
                {
                    result.pParent->pRight = pNode;
                    if (result.pParent == m_pHead->pRight)
                        m_pHead->pRight = pNode;
                }
                else
                {
                    result.pParent->pLeft = pNode;
                    if (result.pParent == m_pHead->pLeft)
                        m_pHead->pLeft = pNode;
                }

                pNode->Color = eColor_Red;

                InsertFixup(pNode);
            }

            ++m_Count;

            return std::make_pair(iterator(pNode), true);
        }

        iterator erase(const_iterator pos)
        {
            return iterator(Erase(pos));
        }

        iterator erase(const_iterator first, const_iterator last)
        {
            return iterator(Erase(first, last));
        }

        size_type erase(const Key& key)
        {
            const SFindResult result = FindLowerBound(key);
            if (LowerBoundDuplicate(result.pBound, key))
            {
                Erase(const_iterator(result.pBound));
                return 1u;
            }
            return 0u;
        }

        void swap(map& other)
        {
            std::swap(m_Comp, other.m_Comp);
            std::swap(m_Alloc, other.m_Alloc);
            std::swap(m_pHead, other.m_pHead);
            std::swap(m_Count, other.m_Count);
        }

        size_type count(const Key& key) const
        {
            return LowerBoundDuplicate(FindLowerBound(key).pBound, key) ? 1u : 0u;
        }

        iterator find(const Key& key)
        {
            return iterator(Find(key));
        }

        const_iterator find(const Key& key) const
        {
            return const_iterator(Find(key));
        }
    };

    BB_ASSERT_SIZEOF((map<int, int>), 0xC);
}

namespace hh = Hedgehog;