
EXE = dtrmm_tune

include ../make.inc

$(EXE): dtrmm_tune.o $(TUNE_UTILS)
	$(CC) $(CFLAGS) dtrmm_tune.o $(TUNE_UTILS_OBJ) $(BLASLIB) -o $@

tune:
	./$(EXE);