### 知识点总结

* 可以使用位向量来表示有限集合。例如：位向量a=[01101001]表示集合A={0,3,5,6}，位向量b=[01010101]表示集合B={0,2,4,6}，使用这种编码集合的方法，布尔运算中的|和&分别对应集合运算中的并和交，而~对应集合运算中的补。在上述例子中，a&b=[0,6]={0,6}。参见《深入理解计算机系统》教材p36页，在大量的应用中都有用到这种抽象表示方法。

* The file system provided by UNIX supports objects (files) which are character arrays of dynamically varying size. UNIX系统支持的文件系统被看作是一个大小动态增长的字符数组。The point to be made in this section is that the second service, which
is what a DBMS wants, is not always efficient when constructed on top of a character array object. The following subsections explain why.但是DBMS认为总是构建在字符数组之上，这不是很高效。

