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


#ifndef _IMG_IO_H
#define _IMG_IO_H

/* UPDATED: 03/15/2005 by MDG */
/* UPDATED: 12/22/2008 by Gregory Fiumara */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <wsq.h>
#include <ihead.h>
#include <ioutil.h>
#include <memalloc.h>
#include <imgutil.h>
#include <util.h>

/* grp4comp.c */
extern void grp4decomp(unsigned char *, int, int, int, unsigned char *, int *);
extern void grp4comp(unsigned char *, int, int, int, unsigned char *, int *);

/* img_io.c */
extern int read_raw_from_filesize(char *, unsigned char **, int *);
extern int write_raw_from_memsize(char *, unsigned char *, const int);
extern int read_ihead(char *, IHEAD **, unsigned char **, int *, int *, int *);
extern int read_raw(char *, unsigned char **, int *, int *, int *);
extern int read_raw_or_ihead_wsq(const int, char *, IHEAD **,
                             unsigned char **, int *, int *, int *);
int write_raw_or_ihead(const int, char *, unsigned char *,
                       const int, const int, const int, const int);

/* readihdr.c */
extern void ReadBinaryRaster(char *, IHEAD **, unsigned char **,
                            int *, int *, int *);
extern void ReadIheadRaster(char *, IHEAD **, unsigned char **,
                            int *, int *, int *);

/* writeihdr.c */
extern void writeihdrfile(char *, IHEAD *, unsigned char *);
extern void writeihdrsubimage(char *, unsigned char *, int, int, int,
                              char *, int, int);
extern void write_fields(char *, char **, int, IHEAD **, unsigned char **,
                         int, int);

#endif /* !_IMG_IO_H */
