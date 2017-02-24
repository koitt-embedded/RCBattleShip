
EXE = zgemm_tune

include ../make.inc

$(EXE): zgemm_tune.o $(TUNE_UTILS)
	$(CC) $(CFLAGS) zgemm_tune.o $(TUNE_UTILS_OBJ) $(BLASLIB) -o $@

tune:
	./$(EXE);