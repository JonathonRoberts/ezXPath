# ezXPath
Simplified functions for returning strings from html and xml hosted locally and online.

Also contains ezCurl


As this uses the libxml and curl libraries that requires the flags:

```
CFLAGS +=-c `xml2-config --cflags` `curl-config --cflags` -Wall

LIBS=`xml2-config --libs` `curl-config --libs`
```

Examples are in main.c

```
char *ezcurl(char *url)

int extern ezXPathXML(char *website,char *expr,char *output[])

int extern ezXPathXMLFile(char *file,char *expr,char *output[])

int extern ezXPathHTML(char *website,char *expr,char *output[])

int extern ezXPathHTMLFile(char *file,char *expr,char *output[])

```
