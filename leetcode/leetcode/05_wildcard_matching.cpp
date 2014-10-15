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
	int source_pos = 0;
	int pattern_pos = 0;
	char source = s[source_pos];
	char pattern = p[pattern_pos];

	while(source != '\0' && pattern !='\0')
	{

		if(pattern != '*')
		{
			if(pattern == '?' || pattern == source){
				source_pos++;
				pattern_pos++;
			}
			else 
			{
				return false;
			}
		}
		else
		{
			pattern_pos ++;
			pattern = p[pattern_pos];
			if(pattern == '\0')
			{
				return true;
			}
			else
			{
				// find the lastest match of this character
				int temp_pos = source_pos;
				char temp = s[temp_pos];
				int last_match_pos = -1;
				while (temp!='\0')
				{
					if(temp == pattern || pattern =='?' || pattern == '*')
					{
						last_match_pos = temp_pos;
					}
					temp_pos ++;
					temp = s[temp_pos];
				}

				if(last_match_pos == -1)
					return false;

				source_pos = last_match_pos;
			}
		}

		source = s[source_pos];
		pattern = p[pattern_pos];
	}

	return source == '\0' && (pattern =='\0' || (pattern == '*' && p[pattern_pos+1] == '\0'));
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

	// would fail...
	match = isMatch("ab", "*?*?");
}