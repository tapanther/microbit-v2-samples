for %%d in (c d e f g h i j k l m n o p q r s t u v w x y z) do (
  if exist %%d:\MICROBIT.HTM (
     xcopy %1 %%d:\
REM      exit
  )
)
