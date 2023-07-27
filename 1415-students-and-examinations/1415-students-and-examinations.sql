# Write your MySQL query statement below
select s1.student_id, s1.student_name, s2.subject_name, COUNT(s3.subject_name) as attended_exams from Students s1 cross join Subjects s2 LEFT JOIN Examinations s3 ON s1.student_id=s3.student_id AND s2.subject_name=s3.subject_name
group by s2.subject_name,s1.student_id 
order by s1.student_id, s2.subject_name ASC