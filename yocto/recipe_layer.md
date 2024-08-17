Variable Assignment Syntax:
---
= : Standard assignment, overwriting any previous value.
+=: Appends to the existing value.
?=: Assigns a value only if the variable is not already set.
:=: Immediate assignment, used to set the value of a variable immediately, rather than deferring it until later.


```
source oe-init-build-env
bitbake-layers create-layer /home/yasmen/meta-iti
bitbake-layers add-layer /home/yasmen/meta-iti
bitbake-layers show-layers
bitbake example
```
```
python __anonymous() {
    # Get the value of the variable MY_CUSTOM_VAR
    var_value = d.getVar('MY_CUSTOM_VAR', True)
    
    # Check the value and modify the task accordingly
    if var_value == "0":
        d.appendVar('do_display_banner', '\n    bb.plain("hi yasmen")\n')
    elif var_value == "1":
        d.appendVar('do_display_banner', '\n    bb.plain("good morning")\n')
}

```

![image](https://github.com/user-attachments/assets/f2834cc0-8fe8-4476-b643-f5e8c151aaa1)
![image](https://github.com/user-attachments/assets/6494ea1e-c64d-42bc-8ab8-274bfb42d154)
![image](https://github.com/user-attachments/assets/204b4232-7981-4845-825f-2fad4cf6e9ec)
![image](https://github.com/user-attachments/assets/31175224-e2a1-48ee-9c84-1f084ffd89d5)


![image](https://github.com/user-attachments/assets/f640f3a9-300c-404b-adb0-f85a4e64c793)
![image](https://github.com/user-attachments/assets/fbd12b67-c64f-464a-89b4-d478996d9797)

![image](https://github.com/user-attachments/assets/9677c95a-3306-4989-b85f-db9bcefcfb53)

```
bitbake example
```
![image](https://github.com/user-attachments/assets/a989cadd-5729-49d3-9691-3216f4ced2d4)
