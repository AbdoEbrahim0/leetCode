char* toLowerCase(char* s) {
	int index = 0;
	
	while (*(s + index) != '\0')
	{
		if (*(s + index) >='A' && *(s + index) <='Z')
		*(s + index) = *(s + index) + 32;
		index++;
	}
	return s;
}