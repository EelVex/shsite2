#include <stdio.h>
#include <stdlib.h>

int main(int argc, char* argv[])
{
	unsigned int count,nxt=1,bli=0,runner=0,position=0;
	unsigned int block[2048] = {0}; /* assume max 1024 blocks per file */
	unsigned int blpos[2048] = {0};
	unsigned int i=0,s=0;
	char r,rn;
	FILE *fp;
	if (argc < 3) { printf("Not enough arguments\n"); return 1; }
		
	count=atoi(argv[1]);
	fp=fopen(argv[2],"r");

	r = fgetc(fp);
	while (!feof(fp)) {
		rn = fgetc(fp); position++;
		if (r == '%' && rn == '{') { 
			runner += nxt; block[bli] = runner; blpos[bli] = position;
			nxt = 1;
			bli++;
		} else if (r == '}' && rn == '%') { 
			runner += nxt; block[bli] = runner; blpos[bli] = position;
			nxt = -1;
			count--;
			if (count == 0) break;
			bli++;
		}
		r = rn;
	}
	rewind(fp);

	s = bli; while(block[s] != (block[bli]-1)) s--;

	i=0;while(i<blpos[bli]-1 && !feof(fp)) {
		r = fgetc(fp);i++;
		if (i>blpos[s]+1) putchar(r);
	}

	fclose(fp);


	return 0;
}
