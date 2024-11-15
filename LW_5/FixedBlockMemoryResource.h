#ifndef FIXEDBLOCKMEMORYRESOURCE_H
#define FIXEDBLOCKMEMORYRESOURCE_H

#include <memory_resource>
#include <list>
#include <cstddef>
#include <cstdlib>

class FixedBlockMemoryResource : public std::pmr::memory_resource {
public:
    explicit FixedBlockMemoryResource(std::size_t block_size);
    ~FixedBlockMemoryResource();

private:
    void* do_allocate(std::size_t bytes, std::size_t alignment) override;
    void do_deallocate(void* p, std::size_t bytes, std::size_t alignment) override;
    bool do_is_equal(const std::pmr::memory_resource& other) const noexcept override;

    std::size_t block_size_;
    char* memory_;
    std::list<std::pair<char*, std::size_t>> free_list_;
};

#endif // FIXEDBLOCKMEMORYRESOURCE_H