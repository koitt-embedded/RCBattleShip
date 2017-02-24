
EXE = zsyrk_tune

include ../make.inc

$(EXE): zsyrk_tune.o $(TUNE_UTILS)
	$(CC) $(CFLAGS) zsyrk_tune.o $(TUNE_UTILS_OBJ) $(BLASLIB) -o $@

tune:
	./$(EXE);