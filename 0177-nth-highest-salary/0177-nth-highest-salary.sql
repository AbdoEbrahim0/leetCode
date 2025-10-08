CREATE FUNCTION getNthHighestSalary(@N INT) RETURNS INT AS
BEGIN
    
        /* Write your T-SQL query statement below. */
        DECLARE @Result INT;

        if  @N<1
            set @Result= null 
        else
            SELECT @Result= salary
            FROM (
                SELECT DISTINCT salary
                FROM Employee
                ORDER BY salary DESC
                OFFSET @N - 1 ROWS FETCH NEXT 1 ROWS ONLY
            ) AS Answer;

    RETURN @Result
END
