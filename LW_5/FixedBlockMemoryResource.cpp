#include "FixedBlockMemoryResource.h"

FixedBlockMemoryResource::FixedBlockMemoryResource(std::size_t block_size)
    : block_size_(block_size), memory_(static_cast<char*>(std::malloc(block_size))) {
    // Инициализация free_list_ с одним блоком размером block_size_
    free_list_.emplace_back(memory_, block_size_);
}

FixedBlockMemoryResource::~FixedBlockMemoryResource() {
    std::free(memory_);
}

void* FixedBlockMemoryResource::do_allocate(std::size_t bytes, std::size_t alignment) {
    if (bytes > block_size_) {
        throw std::bad_alloc();
    }

    auto it = free_list_.begin();
    while (it != free_list_.end()) {
        if (it->second >= bytes) {
            void* ptr = it->first;
            it->first += bytes;
            it->second -= bytes;
            if (it->second == 0) {
                free_list_.erase(it);
            }
            return ptr;
        }
        ++it;
    }

    throw std::bad_alloc();
}

void FixedBlockMemoryResource::do_deallocate(void* p, std::size_t bytes, std::size_t alignment) {
    free_list_.emplace_back(static_cast<char*>(p), bytes);
}

bool FixedBlockMemoryResource::do_is_equal(const std::pmr::memory_resource& other) const noexcept {
    return this == &other;
}