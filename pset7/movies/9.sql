SELECT name from movies
JOIN stars on movies.id = stars.movie_id
JOIN people on stars.person_id = people.id
WHERE year=2004
GROUP by people.id
ORDER by birth;
