SELECT title from movies
JOIN stars on movies.id = stars.movie_id
JOIN people on stars.person_id = people.id
WHERE name in ('Johnny Depp', 'Helena Bonham Carter')
Group by movies.id
HAVING COUNT(DISTINCT people.id) = 2;
