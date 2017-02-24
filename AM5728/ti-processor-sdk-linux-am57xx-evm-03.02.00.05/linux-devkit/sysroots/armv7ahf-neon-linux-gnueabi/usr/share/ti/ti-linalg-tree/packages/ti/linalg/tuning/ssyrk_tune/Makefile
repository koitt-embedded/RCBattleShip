
EXE = ssyrk_tune

include ../make.inc

$(EXE): ssyrk_tune.o $(TUNE_UTILS)
	$(CC) $(CFLAGS) ssyrk_tune.o $(TUNE_UTILS_OBJ) $(BLASLIB) -o $@

tune:
	./$(EXE);