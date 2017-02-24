
EXE = csyrk_tune

include ../make.inc

$(EXE): csyrk_tune.o $(TUNE_UTILS)
	$(CC) $(CFLAGS) csyrk_tune.o $(TUNE_UTILS_OBJ) $(BLASLIB) -o $@

tune:
	./$(EXE);