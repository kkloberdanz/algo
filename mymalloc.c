#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <unistd.h>
#include <assert.h>
#include <stdint.h>

enum {
    HEADER_SIZE = sizeof(size_t)
};

void *mymalloc(size_t requested_bytes) {
    char *p = NULL;
    size_t total_size = requested_bytes + HEADER_SIZE;
    if (!requested_bytes) {
        return NULL;
    }

    /* check for overflow */
    if (requested_bytes > total_size) {
        return NULL;
    }

    p = mmap(0, total_size,
        PROT_READ|PROT_WRITE,
        MAP_PRIVATE|MAP_ANON, -1, 0
    );
    if (p == MAP_FAILED) {
        return NULL;
    } else {
        *((size_t *)p) = total_size;
        /*fprintf(stderr, "%p: mapping: %zu bytes\n", p, ((size_t *)p)[0]);*/
        return p + HEADER_SIZE;
    }
}

void myfree(void *ptr) {
    if (ptr) {
        char *start = (char *)ptr - HEADER_SIZE;
        size_t nbytes = *((size_t *)start);
        /*fprintf(stderr, "%p: unmapping: %zu bytes\n", start, nbytes);*/
        munmap(start, nbytes);
    }
}

void myputs(const char *msg) {
    size_t bytes_written = 0;
    size_t total_bytes = strlen(msg);
    ssize_t ret;
    if (!total_bytes || !msg) {
        return;
    }
    while (bytes_written < total_bytes) {
        ret = write(1, msg + bytes_written, total_bytes - bytes_written);
        if (ret < 0) {
            /* write to stdout failed, let's get out of here! */
            exit(-1);
        }
        bytes_written += ret;
    }
    putchar('\n');
}

int main() {
#   define SIZE 2000
    uint32_t *ptrs[SIZE];
    size_t i;
    size_t j;

    myputs("allocating");
    for (i = 1; i < SIZE; i++) {
        size_t sz = i * SIZE;
        uint32_t *ptr = mymalloc(sz);
        if (!ptr) {
            perror("could not allocate ptr");
            return -1;
        }
        memset(ptr, 0xab, sz);
        ptrs[i] = ptr;
    }

    for (i = 1; i < SIZE; i++) {
        uint32_t *ptr = ptrs[i];
        for (j = 0; j < (SIZE * i) / sizeof(*ptr); j++) {
            /*printf("%x\n", ptr[j]);*/
            assert(ptr[j] == 0xabababab);
        }
        /*printf("%x\n", ptrs[i][0]);*/
    }

    myputs("freeing");
    for (i = 1; i < SIZE; i++) {
        myfree(ptrs[i]);
    }
#   undef SIZE
    myputs("done, check memory usage while I sleep");
    sleep(10);
    return 0;
}
