------- procedure 

CREATE OR REPLACE PROCEDURE avg_rate AS
   p1_id tb_sop_pro.p_id%type;
   avg_rate tb_sop_pro.price%type;
   CURSOR c_product is SELECT p_id FROM tb_sop_pro;
BEGIN
   OPEN c_product;
   LOOP 
      FETCH c_product into p1_id;
			SELECT AVG(price) INTO avg_rate from tb_sop_pro WHERE p_id=p1_id;
      EXIT WHEN c_product%notfound;
      dbms_output.put_line(p1_id || '------' || avg_rate);
   END LOOP;
   	  EXCEPTION
   WHEN NO_DATA_FOUND THEN
		dbms_output.put_line('NOT rated Yet');
   CLOSE c_product;
END;
/


Procedure created.


execute avg_rate;

p001------47000
p002------73000
p003------25000

PL/SQL procedure successfully completed.