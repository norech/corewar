all: build

build:
	$(MAKE) -C ./asm
	$(MAKE) -C ./corewar

coverage:
	$(MAKE) -C ./asm coverage
	$(MAKE) -C ./corewar coverage

clean:
	$(MAKE) -C ./asm clean
	$(MAKE) -C ./corewar clean

fclean: clean
	$(MAKE) -C ./asm fclean
	$(MAKE) -C ./corewar fclean

tests_run:
	$(MAKE) -C ./asm tests_run
	$(MAKE) -C ./corewar tests_run

re: fclean all