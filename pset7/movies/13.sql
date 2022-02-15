SELECT name from people
WHERE people.id in (SELECT stars.person_id from stars
    WHERE stars.movie_id in (SELECT stars.movie_id from stars
    WHERE stars.person_id in (SELECT people.id from people
    WHERE people.name = 'Kevin Bacon' AND
    people.birth =1958)))
AND people.name != 'Kevin Bacon'
GROUP by people.id;
