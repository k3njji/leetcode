class Solution:
    def frequencySort(self, s: str) -> str:
        freq = Counter(s)
        sorted_chars = freq.most_common()
        ans = []
        for char, count in sorted_chars:
            ans.append(char * count)
        return "".join(ans)