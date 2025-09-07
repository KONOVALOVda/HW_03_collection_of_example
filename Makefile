obj-m := ex_list.o ex_queue.o ex_bitmap.o ex_rb_tree.o ex_bin_search.o

KDIR := /lib/modules/$(shell uname -r)/build
PWD  := $(shell pwd)

all: modules

modules:
	$(MAKE) -C $(KDIR) M=$(PWD) modules

clean:
	$(MAKE) -C $(KDIR) M=$(PWD) clean

format:
	clang-format -i *.c

check:
	@for f in *.c; do \
		./scripts/checkpatch.pl --no-tree --file $$f || true; \
	done
