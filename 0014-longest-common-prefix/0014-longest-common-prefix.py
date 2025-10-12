class Solution:
    def longestCommonPrefix(self, strs: List[str]) -> str:
        if not strs:  # If the input list is empty, return empty string
            return ""
        if len(strs) == 1:  # If there's only one string, return it
            return strs[0]
        
        prefix = strs[0]  # Initialize prefix as the first string
        for string in strs[1:]:  # Compare with remaining strings
            # Truncate prefix until it matches the start of the current string
            while string[:len(prefix)] != prefix:
                prefix = prefix[:-1]  # Remove last character of prefix
                if not prefix:  # If prefix becomes empty, return ""
                    return ""
        return prefix  # Return the longest common prefix