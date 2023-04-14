#pragma once

#include <Hedgehog/Base/System/hhAllocator.h>

namespace Hedgehog
{
    template<typename T, typename Allocator = Hedgehog::Base::TAllocator<T>>
    class vector
    {
    protected:
        Allocator m_alloc;
        T* m_begin;
        T* m_end;
        T* m_capacityEnd;

        void ReserveUnchecked(size_t in_NewCapacity)
        {
            T* alloc = m_alloc.allocate(in_NewCapacity);
            std::uninitialized_move(m_begin, m_end, alloc);

            std::destroy(m_begin, m_end);
            m_alloc.deallocate(m_begin, m_capacityEnd - m_begin);

            m_end = alloc + (m_end - m_begin);
            m_begin = alloc;
            m_capacityEnd = alloc + in_NewCapacity;
        }

        void ReserveOne()
        {
            if (m_end == m_capacityEnd)
                ReserveUnchecked(m_begin != m_end ? (m_capacityEnd - m_begin) * 2 : 1);
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

            iterator() : m_ptr(nullptr) {}
            iterator(pointer p) : m_ptr(p) {}

            reference operator*() const { return *m_ptr; }
            pointer operator->() const { return m_ptr; }

            iterator& operator++() { ++m_ptr; return *this; }
            iterator operator++(int) { iterator tmp = *this; ++(*this); return tmp; }

            iterator& operator--() { --m_ptr; return *this; }
            iterator operator--(int) { iterator tmp = *this; --(*this); return tmp; }

            iterator& operator+=(difference_type n) { m_ptr += n; return *this; }
            iterator operator+(difference_type n) const { iterator tmp = *this; return tmp += n; }
            friend iterator operator+(difference_type n, iterator it) { return it + n; }

            iterator& operator-=(difference_type n) { return *this += -n; }
            iterator operator-(difference_type n) const { iterator tmp = *this; return tmp -= n; }
            difference_type operator-(const iterator& other) const { return m_ptr - other.m_ptr; }

            reference operator[](difference_type n) const { return *(*this + n); }

            bool operator==(const iterator& other) const { return m_ptr == other.m_ptr; }
            bool operator!=(const iterator& other) const { return !(*this == other); }
            bool operator<(const iterator& other) const { return m_ptr < other.m_ptr; }
            bool operator<=(const iterator& other) const { return !(other < *this); }
            bool operator>(const iterator& other) const { return other < *this; }
            bool operator>=(const iterator& other) const { return !(*this < other); }

        private:
            pointer m_ptr;

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

            const_iterator() : m_ptr(nullptr) {}
            const_iterator(pointer p) : m_ptr(p) {}
            const_iterator(const iterator& other) : m_ptr(other.m_ptr) {}

            reference operator*() const { return *m_ptr; }
            pointer operator->() const { return m_ptr; }

            const_iterator& operator++() { ++m_ptr; return *this; }
            const_iterator operator++(int) { const_iterator tmp = *this; ++(*this); return tmp; }

            const_iterator& operator--() { --m_ptr; return *this; }
            const_iterator operator--(int) { const_iterator tmp = *this; --(*this); return tmp; }

            const_iterator& operator+=(difference_type n) { m_ptr += n; return *this; }
            const_iterator operator+(difference_type n) const { const_iterator tmp = *this; return tmp += n; }
            friend const_iterator operator+(difference_type n, const_iterator it) { return it + n; }

            const_iterator& operator-=(difference_type n) { return *this += -n; }
            const_iterator operator-(difference_type n) const { const_iterator tmp = *this; return tmp -= n; }
            difference_type operator-(const const_iterator& other) const { return m_ptr - other.m_ptr; }

            reference operator[](difference_type n) const { return *(*this + n); }

            bool operator==(const const_iterator& other) const { return m_ptr == other.m_ptr; }
            bool operator!=(const const_iterator& other) const { return !(*this == other); }
            bool operator<(const const_iterator& other) const { return m_ptr < other.m_ptr; }
            bool operator<=(const const_iterator& other) const { return !(other < *this); }
            bool operator>(const const_iterator& other) const { return other < *this; }
            bool operator>=(const const_iterator& other) const { return !(*this < other); }

        private:
            pointer m_ptr;
            friend class vector;
        };

        using reverse_iterator = std::reverse_iterator<iterator>;
        using const_reverse_iterator = std::reverse_iterator<const_iterator>;

        vector() 
            : m_alloc()
            , m_begin()
            , m_end()
            , m_capacityEnd()
        {
        }

        explicit vector(const Allocator& alloc) 
            : m_alloc(alloc)
            , m_begin()
            , m_end()
            , m_capacityEnd()
        {
        }

        vector(size_type count, const T& value, const Allocator& alloc = Allocator())
            : m_alloc(alloc)
        {
            if (count != 0)
            {
                m_begin = m_alloc.allocate(count);
                m_end = m_begin + count;
                m_capacityEnd = m_end;
                std::uninitialized_fill(m_begin, m_end, value);
            }
            else
            {
                m_begin = nullptr;
                m_end = nullptr;
                m_capacityEnd = nullptr;
            }
        }

        explicit vector(size_type count, const Allocator& alloc = Allocator())
            : m_alloc(alloc)
        {
            if (count != 0)
            {
                m_begin = m_alloc.allocate(count);
                m_end = m_begin + count;
                m_capacityEnd = m_end;
                std::uninitialized_default_construct(m_begin, m_end);
            }
            else
            {
                m_begin = nullptr;
                m_end = nullptr;
                m_capacityEnd = nullptr;
            }
        }

        template<class InputIt>
        vector(InputIt first, InputIt last, const Allocator& alloc = Allocator())
            : m_alloc(alloc)
        {
            auto count = std::distance(first, last);

            if (count != 0)
            {
                m_begin = m_alloc.allocate(count);
                m_end = m_begin + count;
                m_capacityEnd = m_end;
                std::uninitialized_copy(first, last, m_begin);
            }
            else
            {
                m_begin = nullptr;
                m_end = nullptr;
                m_capacityEnd = nullptr;
            }
        }

        vector(const vector& other)
            : m_alloc(other.m_alloc)
        {
            if (!other.empty())
            {
                m_begin = m_alloc.allocate(other.size());
                m_end = m_begin + other.size();
                m_capacityEnd = m_end;
                std::uninitialized_copy(other.m_begin, other.m_end, m_begin);
            }
            else
            {
                m_begin = nullptr;
                m_end = nullptr;
                m_capacityEnd = nullptr;
            }
        }

        vector(const vector& other, const Allocator& alloc)
            : m_alloc(alloc)
        {
            if (!other.empty())
            {
                m_begin = m_alloc.allocate(other.size());
                m_end = m_begin + other.size();
                m_capacityEnd = m_end;
                std::uninitialized_copy(other.m_begin, other.m_end, m_begin);
            }
            else
            {
                m_begin = nullptr;
                m_end = nullptr;
                m_capacityEnd = nullptr;
            }
        }

        vector(vector&& other)
        {
            m_alloc = std::move(other.m_alloc);
            m_begin = other.m_begin;
            m_end = other.m_end;
            m_capacityEnd = other.m_capacityEnd;
            other.m_begin = nullptr;
            other.m_end = nullptr;
            other.m_capacityEnd = nullptr;
        }

        vector(vector&& other, const Allocator& alloc)
            : m_alloc(alloc)
        {
            m_begin = other.m_begin;
            m_end = other.m_end;
            m_capacityEnd = other.m_capacityEnd;
            other.m_begin = nullptr;
            other.m_end = nullptr;
            other.m_capacityEnd = nullptr;
        }

        vector(std::initializer_list<T> init, const Allocator& alloc = Allocator())
            : m_alloc(alloc)
        {
            if (init.size() != 0)
            {
                m_begin = m_alloc.allocate(init.size());
                m_end = m_begin + init.size();
                m_capacityEnd = m_end;
                std::uninitialized_copy(init.begin(), init.end(), m_begin);
            }
            else
            {
                m_begin = nullptr;
                m_end = nullptr;
                m_capacityEnd = nullptr;
            }
        }

        ~vector()
        {
            std::destroy(m_begin, m_end);
            m_alloc.deallocate(m_begin, m_capacityEnd - m_begin);

            m_begin = nullptr;
            m_end = nullptr;
            m_capacityEnd = nullptr;
        }

        vector& operator=(const vector& other)
        {
            if (this != &other)
            {
                clear();

                if (!other.empty())
                {
                    reserve(other.size());
                    m_end += other.size();
                    std::uninitialized_copy(other.m_begin, other.m_end, m_begin);
                }
            }
            return *this;
        }

        vector& operator=(vector&& other)
        {
            if (this != &other)
            {
                m_begin = other.m_begin;
                m_end = other.m_end;
                m_capacityEnd = other.m_capacityEnd;
                other.m_begin = nullptr;
                other.m_end = nullptr;
                other.m_capacityEnd = nullptr;
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
                m_end += count;
                std::uninitialized_fill(m_begin, m_end, value);
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
                std::uninitialized_copy(first, last, m_begin);
                m_end += count;
            }
        }

        void assign(std::initializer_list<T> ilist)
        {
            clear();

            if (ilist.size() != 0)
            {
                reserve(ilist.size());
                std::uninitialized_copy(ilist.begin(), ilist.end(), m_begin);
                m_end += ilist.size();
            }
        }

        allocator_type get_allocator() const
        {
            return m_alloc;
        }

        reference at(size_type pos)
        {
            return m_begin[pos];
        }

        const_reference at(size_type pos) const
        {
            return m_begin[pos];
        }

        reference operator[](size_type pos)
        {
            return m_begin[pos];
        }

        const_reference operator[](size_type pos) const
        {
            return m_begin[pos];
        }

        reference front()
        {
            return m_begin[0];
        }

        const_reference front() const
        {
            return m_begin[0];
        }

        reference back()
        {
            return m_end[-1];
        }

        const_reference back() const
        {
            return m_end[-1];
        }

        T* data()
        {
            return m_begin;
        }

        const T* data() const
        {
            return m_begin;
        }

        iterator begin()
        {
            return iterator(m_begin);
        }

        const_iterator begin() const
        {
            return const_iterator(m_begin);
        }

        const_iterator cbegin() const
        {
            return const_iterator(m_begin);
        }

        iterator end()
        {
            return iterator(m_end);
        }

        const_iterator end() const
        {
            return const_iterator(m_end);
        }

        const_iterator cend() const
        {
            return const_iterator(m_end);
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
            return m_begin == m_end;
        }

        size_type size() const
        {
            return m_end - m_begin;
        }

        size_type max_size() const
        {
            return ~0u;
        }

        void reserve(size_type new_cap)
        {
            if (m_begin + new_cap > m_capacityEnd)
                ReserveUnchecked(new_cap);
        }

        size_type capacity() const
        {
            return m_capacityEnd - m_begin;
        }

        void shrink_to_fit()
        {
            if (m_begin != m_end)
            {
                ReserveUnchecked(m_end - m_begin);
            }
            else
            {
                m_alloc.deallocate(m_begin, m_capacityEnd - m_begin);
                m_begin = nullptr;
                m_end = nullptr;
                m_capacityEnd = nullptr;
            }
        }

        void clear()
        {
            std::destroy(m_begin, m_end);
            m_end = m_begin;
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
            if (m_end == m_capacityEnd)
            {
                size_t capacity = m_begin != m_end ? (m_capacityEnd - m_begin) * 2 : 1;

                T* alloc = m_alloc.allocate(capacity);
                std::uninitialized_move(m_begin, m_begin + offset, alloc);
                new (alloc + offset) T(std::forward<Args>(args)...);
                std::uninitialized_move(m_begin + offset, m_end, alloc + offset + 1);

                std::destroy(m_begin, m_end);
                m_alloc.deallocate(m_begin, m_capacityEnd - m_begin);

                m_end = alloc + (m_end - m_begin) + 1;
                m_begin = alloc;
                m_capacityEnd = alloc + capacity;
            }
            else
            {
                new (m_end) T();
                std::move_backward(m_begin + offset, m_end, m_end + 1);
                new (m_begin + offset) T(std::forward<Args>(args)...);
                ++m_end;
            }
            return iterator(m_begin + offset);
        }

        iterator erase(const_iterator pos)
        {
            T* pPos = m_begin + (pos - begin());
            std::move(pPos + 1, m_end, pPos);

            --m_end;
            m_end->~T();

            return iterator(pPos);
        }

        iterator erase(const_iterator first, const_iterator last)
        {
            T* pFirst = m_begin + (first - begin());
            T* pLast = m_begin + (last - begin());

            std::move(pLast, m_end, pFirst);

            T* pNewLast = m_end - (pLast - pFirst);
            std::destroy(pNewLast, m_end);
            m_end = pNewLast;

            return iterator(pFirst);
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
            new (m_end) T(std::forward<Args>(args)...);
            return *(m_end++);
        }

        void pop_back()
        {
            --m_end;
            m_end->~T();
        }

        void resize(size_type count)
        {
            if (m_begin + count < m_end)
            {
                std::destroy(m_begin + count, m_end);
            }
            else if (m_begin + count > m_end)
            {
                ReserveUnchecked(count);
                std::uninitialized_default_construct(m_end, m_begin + count);
            }
            m_end = m_begin + count;
        }

        void resize(size_type count, const value_type& value)
        {
            if (m_begin + count < m_end)
            {
                std::destroy(m_begin + count, m_end);
            }
            else if (m_begin + count > m_end)
            {
                ReserveUnchecked(count);
                std::uninitialized_fill(m_end, m_begin + count, value);
            }
            m_end = m_begin + count;
        }

        void swap(vector& other)
        {
            std::swap(m_begin, other.m_begin);
            std::swap(m_end, other.m_end);
            std::swap(m_capacityEnd, other.m_capacityEnd);
        }
    };
}

namespace hh = Hedgehog;