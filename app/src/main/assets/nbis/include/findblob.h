/*******************************************************************************

License: 
This software was developed at the National Institute of Standards and 
Technology (NIST) by employees of the Federal Government in the course 
of their official duties. Pursuant to title 17 Section 105 of the 
United States Code, this software is not subject to copyright protection 
and is in the public domain. NIST assumes no responsibility  whatsoever for 
its use by other parties, and makes no guarantees, expressed or implied, 
about its quality, reliability, or any other characteristic. 

This software has been determined to be outside the scope of the EAR
(see Part 734.3 of the EAR for exact details) as it has been created solely
by employees of the U.S. Government; it is freely distributed with no
licensing requirements; and it is considered public domain.  Therefore,
it is permissible to distribute this software as a free download from the
internet.

Disclaimer: 
This software was developed to promote biometric standards and biometric
technology testing for the Federal Government in accordance with the USA
PATRIOT Act and the Enhanced Border Security and Visa Entry Reform Act.
Specific hardware and software products identified in this software were used
in order to perform the software development.  In no case does such
identification imply recommendation or endorsement by the National Institute
of Standards and Technology, nor does it imply that the products and equipment
identified are necessarily the best available for the purpose.  

*******************************************************************************/


#ifndef _FINDBLOB_H
#define _FINDBLOB_H

/************************************************************/
/*         File Name: Findblob.h                            */
/*         Package:   NIST Blob Finding Utilities           */
/*         Author:    G. T. Candela                         */
/*         Dated:     03/01/1994                            */
/*         Updated:   03/14/2005 by MDG                     */
/************************************************************/
/* Header file for the findblob routine. */

/* Manifest constant values of some input flags. */

/* Values for erase_flag */
#define ERASE      0
#define NO_ERASE   1

/* Values for alloc_flag */
#define ALLOC      0
#define NO_ALLOC   1

/* Values for out_flag */
#define ORIG_BLOB  0
#define W_H_BLOB   1
#define BOUND_BLOB 2

/* connectivity codes */
#define CONNECT4 44
#define CONNECT8 88

/* Starting, growth-increment, and maximum number of elts for the
   internal list used by findblob.  (Each list elt occupies 12 bytes.)	*/
#define LIST_STARTSIZE  6144		/* might as well keep mults of	*/
#define LIST_INCR       2048		/* 2 so that max list size	*/
#define LIST_MAXSIZE    8388608         /* is 12*8*1024*1024 = 96Mb	*/

typedef struct { /* info about one run of pixels */
  unsigned short y;
  unsigned char *w_on, *e_off;
} RUN;

/* findblob.c */
extern int findblob(unsigned char *, int, int, int, int, int, int *, int *,
                    unsigned char **, int *, int *, int *, int *);
extern int findblob8(unsigned char *, int, int, int, int, int, int *, int *,
                     unsigned char **, int *, int *, int *, int *);
extern int findblobnruns(unsigned char *, int, int, int, int, int,
                     int *, int *,
                     unsigned char **, int *, int *, int *, int *,
                     RUN **, RUN **, RUN **);
extern int findblobnruns8(unsigned char *, int, int, int, int, int,
                     int *, int *,
                     unsigned char **, int *, int *, int *, int *,
                     RUN **, RUN **, RUN **);
extern int findblob_connect(unsigned char *, int, int, int, int, int,
                     int *, int *,
                     unsigned char **, int *, int *, int *, int *,
                     RUN **, RUN **, RUN **, int);
extern void findblob_seed_to_run(unsigned short, unsigned char *);
extern void findblob_grow_n(void);
extern void findblob_8grow_n(void);
extern void findblob_grow_s(void);
extern void findblob_8grow_s(void);
extern void findblob_realloc_list(void);
extern int findblob_stats_rw(unsigned char *, int, int, int *, int *,
                             int *, int *, int *, int *);
extern int findblob_stats_cl(unsigned char *, int, int, int *, int *,
                             int *, int *, int *, int *);
extern void end_findblobs(void);

#endif  /* !_FINDBLOB_H */
