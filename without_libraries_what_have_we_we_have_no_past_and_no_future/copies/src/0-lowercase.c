char lowercase(char c)
{
  if (c >=65 && c <= 90) 	/* if uppercase letter */
    return c+32;		/* return lowercase */
  return c;			/* else, return without change */
}
