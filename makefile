run:
	@gcc main.c SDB.c SDBAPP.c -o main.exe
	@./main.exe


clean:
	@rm ./main.exe
	@echo "Files Removed"
