char uppercase(char c)
{
  if (c>96 && c<123) // if lowercase letter
    return c-32; // return uppercase
  return c; // if not lowercase letter, return unchanged
}

