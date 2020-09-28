Tokenizer: userInt.o history.o tokenizer.o
	cc -o tokens userInt.o history.o tokenizer.o

userInt.o: history.h tokenizer.h userInt.c

tokenizer.o: tokenizer.h tokenizer.c

history.o: history.h history.c

clean:

	rm -f *.o tokens

