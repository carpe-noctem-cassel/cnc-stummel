{
  "id" : 1571241152555,
  "name" : "StummelMaster",
  "comment" : "",
  "relativeDirectory" : "",
  "variables" : [ ],
  "masterPlan" : true,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : null,
  "entryPoints" : [ {
    "id" : 1571241176070,
    "name" : "1571241176070",
    "comment" : "",
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 100,
    "task" : "taskr.tsk#1570633373655",
    "state" : 1571241177902,
    "plan" : 1571241152555
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1571241177902,
    "name" : "Stop",
    "comment" : "",
    "entryPoint" : 1571241176070,
    "parentPlan" : 1571241152555,
    "abstractPlans" : [ "Behaviours/Stop.beh#1571238310927" ],
    "variableBindings" : [ ],
    "outTransitions" : [ 1571241181819 ],
    "inTransitions" : [ 1571241197397 ]
  }, {
    "type" : "State",
    "id" : 1571241178465,
    "name" : "Start",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1571241152555,
    "abstractPlans" : [ "Exploration/Explore.pml#1571241166731" ],
    "variableBindings" : [ ],
    "outTransitions" : [ 1571241197397 ],
    "inTransitions" : [ 1571241181819 ]
  } ],
  "transitions" : [ {
    "id" : 1571241181819,
    "name" : "FromStopToStart",
    "comment" : "MISSING_COMMENT",
    "inState" : 1571241177902,
    "outState" : 1571241178465,
    "preCondition" : null,
    "synchronisation" : null
  }, {
    "id" : 1571241197397,
    "name" : "FromStartToStop",
    "comment" : "MISSING_COMMENT",
    "inState" : 1571241178465,
    "outState" : 1571241177902,
    "preCondition" : null,
    "synchronisation" : null
  } ],
  "synchronisations" : [ ]
}