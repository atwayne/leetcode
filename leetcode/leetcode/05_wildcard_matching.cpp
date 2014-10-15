/*

https://oj.leetcode.com/problems/wildcard-matching/

Wildcard Matching 

Implement wildcard pattern matching with support for '?' and '*'.

'?' Matches any single character.
'*' Matches any sequence of characters (including the empty sequence).

The matching should cover the entire input string (not partial).

The function prototype should be:
bool isMatch(const char *s, const char *p)

Some examples:
isMatch("aa","a") -> false
isMatch("aa","aa") -> true
isMatch("aaa","aa") -> false
isMatch("aa", "*") -> true
isMatch("aa", "a*") -> true
isMatch("ab", "?*") -> true
isMatch("aab", "c*a*b") -> false

*/

bool isMatch(const char *s, const char *p) {
	const char* wildchar = nullptr;
	const char* ss = s;
	while (*s){
		//advancing both pointers when (both characters match) or ('?' found in pattern)
		//note that *p will not advance beyond its length 
		if ((*p == '?') || (*p == *s)){ s++; p++; continue; }

		// * found in pattern, track index of *, only advancing pattern pointer 
		if (*p == '*'){ wildchar = p++; ss = s; continue; }

		//current characters didn't match, last pattern pointer was *, current pattern pointer is not *
		//only advancing pattern pointer
		if (wildchar){ p = wildchar + 1; s = ++ss; continue; }

		//current pattern pointer is not star, last patter pointer was not *
		//characters do not match
		return false;
	}

	//check for remaining characters in pattern
	while (*p == '*'){ p++; }

	return !*p;
}

void isMatch_test()
{
	bool match;
	match = isMatch("aa","a");
	match = isMatch("aa","a");
	match = isMatch("aa","aa");
	match = isMatch("aaa","aa");
	match = isMatch("aa", "*");
	match = isMatch("aa", "a*");
	match = isMatch("ab", "?*");
	match = isMatch("aab", "c*a*b");
	match = isMatch("ab", "*a");
	match = isMatch("", "*");
	match = isMatch("b", "?*?");
	match = isMatch("a", "a*");
	match = isMatch("c", "*?*");
	match = isMatch("hi", "*?");

	match = isMatch("ab", "*?*?");
	match = isMatch("abcd", "*b*d");
}