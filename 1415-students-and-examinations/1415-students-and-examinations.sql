/* Write your T-SQL query statement below */
select stud.student_id, stud.student_name ,sub.subject_name,
count(exam.subject_name)  AS attended_exams
from Students as stud  cross join Subjects as sub
left join Examinations as exam
on exam.student_id=stud.student_id and exam.subject_name =sub.subject_name
group by stud.student_id, stud.student_name, sub.subject_name
order by stud.student_id asc , sub.subject_name asc;