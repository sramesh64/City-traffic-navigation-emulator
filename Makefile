all:	main.cpp HeapClassdef.cpp GraphClassdef.cpp VertexClassdef.cpp EdgeClassdef.cpp
	g++ -g -std=c++11 main.cpp HeapClassdef.cpp GraphClassdef.cpp VertexClassdef.cpp EdgeClassdef.cpp