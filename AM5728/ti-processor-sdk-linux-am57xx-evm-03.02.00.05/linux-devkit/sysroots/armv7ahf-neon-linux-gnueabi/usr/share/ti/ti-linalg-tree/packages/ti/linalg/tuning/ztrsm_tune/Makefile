
EXE = ztrsm_tune

include ../make.inc

$(EXE): ztrsm_tune.o $(TUNE_UTILS)
	$(CC) $(CFLAGS) ztrsm_tune.o $(TUNE_UTILS_OBJ) $(BLASLIB) -o $@

tune:
	./$(EXE);