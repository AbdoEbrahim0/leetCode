/* Write your T-SQL query statement below */
--select tweet_id from Tweets where len(content)>15;

select tweet_id
From Tweets
where len (content)>15 