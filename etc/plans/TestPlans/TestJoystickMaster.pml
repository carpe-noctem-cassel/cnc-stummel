<?xml version="1.0" encoding="ASCII"?>
<alica:Plan xmi:version="2.0" xmlns:xmi="http://www.omg.org/XMI" xmlns:xsi="http://www.w3.org/2001/XMLSchema-instance" xmlns:alica="http:///de.uni_kassel.vs.cn" id="1531320805154" name="TestJoystickMaster" comment="" masterPlan="true" utilityFunction="" utilityThreshold="0.1" destinationPath="Plans/TestPlans" priority="0.0" minCardinality="0" maxCardinality="2147483647">
  <states id="1531320805155" name="Joystick" comment="" entryPoint="1531320805156">
    <plans xsi:type="alica:BehaviourConfiguration">../Joystick.beh#1531320972586</plans>
  </states>
  <entryPoints id="1531320805156" name="MISSING_NAME" comment="" successRequired="false" minCardinality="0" maxCardinality="2147483647">
    <task>../../Misc/taskrepository.tsk#1530108941014</task>
    <state>#1531320805155</state>
  </entryPoints>
</alica:Plan>
