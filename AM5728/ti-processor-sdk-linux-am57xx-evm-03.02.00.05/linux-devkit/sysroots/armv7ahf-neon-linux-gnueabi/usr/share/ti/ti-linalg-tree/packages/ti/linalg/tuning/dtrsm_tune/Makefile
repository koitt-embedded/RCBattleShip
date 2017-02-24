
EXE = dtrsm_tune

include ../make.inc

$(EXE): dtrsm_tune.o $(TUNE_UTILS)
	$(CC) $(CFLAGS) dtrsm_tune.o $(TUNE_UTILS_OBJ) $(BLASLIB) -o $@

tune:
	./$(EXE);