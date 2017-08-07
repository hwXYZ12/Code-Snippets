# a cookie if you can figure out what this does ;)

void whoknows(std::string & s, int len, int pos) {

	if (len <= 0) {
		return;
	}

	char * t = &s[pos];
	whoknows(s, len - 1, pos + 1);
	s[len-1] = *t;

}