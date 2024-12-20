<<<<<<< HEAD:8 chapter/Makefile

#Переопределение команды удаления файлов для Windows
RM=del
#Правило сборки исполняемого файла из объектных.
#CXX - переменная для команды компилятора. (По умолчанию g++.)


#Фиктивное правило для очистки каталога от созданных в процессе сборки файлов.
#Для его вызова нужно указать clean после команды make.

l807302o=L807_302.o L807_302test.o
L807302.exe: $(l807302o)
	$(CXX) -o L807302.exe $(l807302o)

L807_302.o: L807_302.c
	$(CXX) -c L807_302.c

L807_302test.o: L807_302test.c L807_302.h
	$(CXX) -c L807_302test.c

l808303o=L808_303.o L808_303test.o
L808303.exe: $(l808303o)
	$(CXX) -o L808_303.exe $(l808303o)

L808_303.o: L808_303.c L812_307.h L807_302.h L811_307.h L806_301.h
	$(CXX) -c L808_303.c

L808_303test.o: L808_303test.c L808_303.h
	$(CXX) -c L808_303test.c

l809305o=L809_305.o L809_305test.o
L809305.exe: $(l809305o)
	$(CXX) -o L809305.exe $(l809305o)

L809_305.o: L809_305.c L806_301.h L807_302.h L813_307.h
	$(CXX) -c L809_305.c

L809_305test.o: L809_305test.c L809_305.h L808_303.h
	$(CXX) -c L809_305test.c

l810306o=L810_306.o L810_306test.o
L810306.exe: $(l810306o)
	$(CXX) -o L810306.exe $(l810306o)

L810_306.o: L810_306.c L806_301.h L807_302.h
	$(CXX) -c L810_306.c

L810_306test.o: L810_306test.c L810_306.h
	$(CXX) -c L810_306test.c

l811307o=L811_307.o L811_307test.o
L811307.exe: $(l811307o)
	$(CXX) -o L811307.exe $(l811307o)

L811_307.o: L811_307.c
	$(CXX) -c L811_307.c

L811_307test.o: L811_307test.c L811_307.h
	$(CXX) -c L811_307test.c

l812307o=L812_307.o L812_307test.o
L812307.exe: $(l812307o)
	$(CXX) -o L812307.exe $(l812307o)

L812_307.o: L812_307.c
	$(CXX) -c L812_307.c

L812_307test.o: L812_307test.c L812_307.h
	$(CXX) -c L812_307test.c

.PHONY: clean
clean:
=======
# Определение компилятора (gcc для Linux, g++ для Windows)
CXX=gcc

# Определение команды удаления и расширение файла в зависимости от ОС
ifeq ($(OS),Windows_NT)
	RM=del
	EXT=.exe
else
	RM=rm
	EXT=

endif
#Правило сборки исполняемого файла из объектных.
#CXX - переменная для команды компилятора. (По умолчанию g++.)
objects=m.o kva.o

m.exe: $(objects)
	$(CXX) -o m.exe $(objects)
	
#Правило компиляции исходного файла с завизимостью от заголовочного файла в объектный
m.o: m.c kva.h
	$(CXX) -c m.c

#Правило компиляции исходного файла в объектный
kva.o: kva.c
	$(CXX) -c kva.c

#Фиктивное правило для очистки каталога от созданных в процессе сборки файлов.
#Для его вызова нужно указать clean после команды make.

l807302o=L807_302.o L807_302test.o
L807302.exe: $(l807302o)
	$(CXX) -o L807302.exe $(l807302o)

L807_302.o: L807_302.c
	$(CXX) -c L807_302.c

L807_302test.o: L807_302test.c L807_302.h
	$(CXX) -c L807_302test.c

l808303o=L808_303.o L808_303test.o
L808303.exe: $(l808303o)
	$(CXX) -o L808_303.exe $(l808303o)

L808_303.o: L808_303.c L812_307.h L807_302.h L811_307.h L806_301.h
	$(CXX) -c L808_303.c

L808_303test.o: L808_303test.c L808_303.h
	$(CXX) -c L808_303test.c

l809305o=L809_305.o L809_305test.o
L809305.exe: $(l809305o)
	$(CXX) -o L809305.exe $(l809305o)

L809_305.o: L809_305.c L806_301.h L807_302.h L813_307.h
	$(CXX) -c L809_305.c

L809_305test.o: L809_305test.c L809_305.h L808_303.h
	$(CXX) -c L809_305test.c

l810306o=L810_306.o L810_306test.o
L810306.exe: $(l810306o)
	$(CXX) -o L810306.exe $(l810306o)

L810_306.o: L810_306.c L806_301.h L807_302.h
	$(CXX) -c L810_306.c

L810_306test.o: L810_306test.c L810_306.h
	$(CXX) -c L810_306test.c

l811307o=L811_307.o L811_307test.o
L811307.exe: $(l811307o)
	$(CXX) -o L811307.exe $(l811307o)

L811_307.o: L811_307.c
	$(CXX) -c L811_307.c

L811_307test.o: L811_307test.c L811_307.h
	$(CXX) -c L811_307test.c

l812307o=L812_307.o L812_307test.o
L812307.exe: $(l812307o)
	$(CXX) -o L812307.exe $(l812307o)

L812_307.o: L812_307.c
	$(CXX) -c L812_307.c

L812_307test.o: L812_307test.c L812_307.h
	$(CXX) -c L812_307test.c

.PHONY: clean
clean:
>>>>>>> 69800ad3492843e02fc17149acac64708921c85f:Makefile
	$(RM) $(objects) $(l807302o) $(l808303o) $(l809305o) $(l810306o) $(l811307o) $(l812307o) m.exe L807302.exe L808303.exe L809305.exe L810306.exe L811307.exe L812307.exe