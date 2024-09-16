#!/usr/bin/python3
"""
0-count module
"""

import requests


def count_words(subreddit, word_list, after=None, word_count={}):
    """
    Recursively queries the Reddit API, parses the titles of all hot articles,
    and prints a sorted count of given keywords.
    """
    headers = {'User-Agent': 'Mozilla/5.0'}
    url = f"https://www.reddit.com/r/{subreddit}/hot.json"

    params = {'after': after, 'limit': 100}

    try:
        response = requests.get(url, headers=headers, params=params, allow_redirects=False)
        if response.status_code != 200:
            return  # Invalid subreddit or other error

        data = response.json().get("data")
        children = data.get("children")
        after = data.get("after")

        for article in children:
            title = article.get("data").get("title").lower().split()
            for word in word_list:
                count = title.count(word.lower())
                if count > 0:
                    if word.lower() in word_count:
                        word_count[word.lower()] += count
                    else:
                        word_count[word.lower()] = count

        if after:
            return count_words(subreddit, word_list, after, word_count)
        else:
            if word_count:
                sorted_count = sorted(word_count.items(), key=lambda x: (-x[1], x[0]))
                for word, count in sorted_count:
                    if count > 0:
                        print(f"{word}: {count}")
    except Exception:
        return  # Handle exceptions silently for invalid subreddits or other issues

if __name__ == "__main__":
    import sys
    if len(sys.argv) < 3:
        print(f"Usage: {sys.argv[0]} <subreddit> <list of keywords>")
    else:
        subreddit = sys.argv[1]
        word_list = sys.argv[2].split()
        count_words(subreddit, word_list)
