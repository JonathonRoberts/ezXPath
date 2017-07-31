#include <stdio.h>
#include "ezXPath.c"

#define MAXELEMENTS 200 /* Maximum number of results to return */

 /*
 * ezXpath examples
 */

int main(){
	char *output[MAXELEMENTS];
	int i;
	int size;

	char *website = "https://www.sitemaps.org/sitemap.xml";
	char *xpath = "/*[local-name() = 'urlset']/*[local-name() = 'url']/*[local-name() = 'loc']";
	size = ezXPathXML(website,xpath,output);
	if(size!=0){
		printf("Found %d elements:\n",size);
		for(i =0;i<size;i++){
			printf("%s\n",output[i]);
			free(output[i]);
		}
	}

	char *file = "sitemap.xml";
	xpath = "/*[local-name() = 'urlset']/*[local-name() = 'url']/*[local-name() = 'loc']";
	size = ezXPathXMLFile(file,xpath,output);
	if(size!=0){
		printf("Found %d elements:\n",size);
		for(i =0;i<size;i++){
			printf("%s\n",output[i]);
			free(output[i]);
		}
	}

	website = "http://www.jokesoftheday.net/";
	xpath = "id('content')/div[3]/div[1]";
	size = ezXPathHTML(website,xpath,output);
	if(size!=0){
		printf("Found %d elements:\n",size);
		for(i =0;i<size;i++){
			printf("%s\n",output[i]);
			free(output[i]);
		}
	}

	file = "example.com";
	xpath = "/html/head/title";
	size = ezXPathHTMLFile(file,xpath,output);
	if(size!=0){
		printf("Found %d elements:\n",size);
		for(i =0;i<size;i++){
			printf("%s\n",output[i]);
			free(output[i]);
		}
	}
	return 1;
}
