SELECT movies.title, ratings.rating
FROM ratings, movies
WHERE movies.id = ratings.movie_id
AND movies.year = '2010'ORDER BY ratings.rating DESC