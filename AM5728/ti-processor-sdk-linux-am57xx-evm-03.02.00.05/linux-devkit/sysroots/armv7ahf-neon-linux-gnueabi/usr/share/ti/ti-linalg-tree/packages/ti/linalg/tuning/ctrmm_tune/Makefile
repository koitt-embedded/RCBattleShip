
EXE = ctrmm_tune

include ../make.inc

$(EXE): ctrmm_tune.o $(TUNE_UTILS)
	$(CC) $(CFLAGS) ctrmm_tune.o $(TUNE_UTILS_OBJ) $(BLASLIB) -o $@

tune:
	./$(EXE);