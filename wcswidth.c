/* simple wrapper to expose the wcswidth function
 * (c) Florian Cauvin
 */

#define _XOPEN_SOURCE
#include <wchar.h>
#include <locale.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

int main(int argc, char *argv[])
{
   if (argc != 2) {
      fprintf(stderr, "Usage: %s <string>\n", argv[0]);
      exit(EXIT_FAILURE);
   }

   /* convert argv[1] to a wchar string (in variable wcs): */

   /* we can allocate wchar based on number of bytes,
      this is simpler but we may be over allocating:
        | size_t n = strlen(argv[1]);
      or we can use do the conversion to wchar string
      to define the size:
        | size_t n = mbstowcs(NULL, argv[1], 0);
        |  if (mbstowcs(wcs, argv[1], n+1) == (size_t) -1) {
        |     perror("mbstowcs");
        |     exit(EXIT_FAILURE);
        |  }
   */
   size_t n = strlen(argv[1]);

   wchar_t *wcs = malloc((n+1) * sizeof(wchar_t));
   if (!wcs) {
      perror("malloc");
      exit(EXIT_FAILURE);
   }
   if (setlocale(LC_ALL, "") == NULL) {
      perror("setlocale");
      exit(EXIT_FAILURE);
   }
   if (mbstowcs(wcs, argv[1], n+1) == (size_t) -1) {
      perror("mbstowcs");
      exit(EXIT_FAILURE);
   }


   /* then we can finally use wcswidth: */
   int w = wcswidth(wcs, n);
   free(wcs);
   if (w < 0)
      return 1;
   printf("%d\n", w);
   return 0;
}
