class Solution:
    def suggestedProducts(self, products: List[str], searchWord: str) -> List[List[str]]:
        products.sort()

        ans = []

        for i in range(len(searchWord)):
            temp = []
            prefix = searchWord[:i+1]

            for pr in products:
                if prefix == pr[:i+1]:
                    temp.append(pr)

                if len(temp) == 3:
                    break

            ans.append(temp)

        return ans