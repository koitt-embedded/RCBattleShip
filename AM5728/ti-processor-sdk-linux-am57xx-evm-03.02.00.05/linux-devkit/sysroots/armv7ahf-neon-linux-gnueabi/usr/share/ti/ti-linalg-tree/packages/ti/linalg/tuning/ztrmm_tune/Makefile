
EXE = ztrmm_tune

include ../make.inc

$(EXE): ztrmm_tune.o $(TUNE_UTILS)
	$(CC) $(CFLAGS) ztrmm_tune.o $(TUNE_UTILS_OBJ) $(BLASLIB) -o $@

tune:
	./$(EXE);