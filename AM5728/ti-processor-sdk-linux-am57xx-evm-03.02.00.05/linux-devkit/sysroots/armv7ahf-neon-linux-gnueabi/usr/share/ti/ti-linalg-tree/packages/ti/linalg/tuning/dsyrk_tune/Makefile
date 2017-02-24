
EXE = dsyrk_tune

include ../make.inc

$(EXE): dsyrk_tune.o $(TUNE_UTILS)
	$(CC) $(CFLAGS) dsyrk_tune.o $(TUNE_UTILS_OBJ) $(BLASLIB) -o $@

tune:
	./$(EXE);