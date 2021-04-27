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

re: fclean all