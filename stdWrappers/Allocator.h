#ifndef _ALLOCATOR_
#define _ALLOCATOR_

#include "AllocatorWrapper.h"

#include <limits>
#include <new>
#include <utility>

	template<typename T, typename Wrapper = AllocatorWrapper>
	class Allocator{
    private:
        Wrapper strategy;
	public:
		using value_type = T;
		using pointer = T*;
		using reference = T&;
		using r_reference = T&&;
		using const_pointer = const T*;
		using const_reference = const T&;
		using size_type = size_t;
		using difference_type = ptrdiff_t;

		//departed in c++20
		template<class Type>
		struct rebind {
			using other = Allocator<Type>;
		};

		Allocator() : strategy(0) {};

        Allocator(int sz) : strategy(sz) {}

		Allocator(const Allocator& alloc) = delete;

		~Allocator() = default;

		template<class U>
		Allocator(const Allocator<U>& alloc) {}

		pointer address(reference x) const { return &x; }
		//const_pointer address(const_reference x) const {return &x; };

		pointer allocate(size_type n){
			if(n > this->max_size())
				return nullptr;
			return reinterpret_cast<pointer>(strategy.allocate(n * sizeof(value_type)));
		}

		void deallocate(pointer ptr, size_type sz){
			 strategy.deallocate(ptr, sz);
		}

		void construct(pointer p, const_reference val){
			::new (reinterpret_cast<void*>(p)) value_type(val);
		}

		template<typename... Args>
		void construct(pointer p, Args&&... val) {
			::new (reinterpret_cast<void*>(p)) value_type(std::forward<Args>(val)...);
		}

		void destroy(pointer p){
			p->~value_type();
		}

		//departed in c++20
		size_type max_size() const{
			return std::numeric_limits<size_type>::max() / sizeof(value_type);
		}
	};

#endif

