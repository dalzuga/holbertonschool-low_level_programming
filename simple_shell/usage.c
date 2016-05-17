char usage(int argc, int expected, char *str)
{
	if (argc != expected) {
                printf("%s", str);
		return 1;
	}

        return 0;
}
