{
  "id" : 1571241166731,
  "name" : "Explore",
  "comment" : "",
  "relativeDirectory" : "Exploration",
  "variables" : [ ],
  "masterPlan" : false,
  "utilityThreshold" : 0.0,
  "preCondition" : null,
  "runtimeCondition" : null,
  "entryPoints" : [ {
    "id" : 1571241343120,
    "name" : "1571241343120",
    "comment" : "",
    "successRequired" : false,
    "minCardinality" : 0,
    "maxCardinality" : 0,
    "task" : "taskr.tsk#1570633373655",
    "state" : 1571241667090,
    "plan" : 1571241166731
  } ],
  "states" : [ {
    "type" : "State",
    "id" : 1571241667090,
    "name" : "DriveToLab",
    "comment" : "",
    "entryPoint" : 1571241343120,
    "parentPlan" : 1571241166731,
    "abstractPlans" : [ ],
    "variableBindings" : [ ],
    "outTransitions" : [ 1573054018526 ],
    "inTransitions" : [ 1573054078777 ]
  }, {
    "type" : "State",
    "id" : 1571241667604,
    "name" : "DriveToHallway",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1571241166731,
    "abstractPlans" : [ ],
    "variableBindings" : [ ],
    "outTransitions" : [ 1573054021223 ],
    "inTransitions" : [ 1573054018526 ]
  }, {
    "type" : "State",
    "id" : 1571241671453,
    "name" : "DriveToOffices",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1571241166731,
    "abstractPlans" : [ ],
    "variableBindings" : [ ],
    "outTransitions" : [ 1573054023369 ],
    "inTransitions" : [ 1573054021223 ]
  }, {
    "type" : "State",
    "id" : 1571241672784,
    "name" : "DriveToKitchen",
    "comment" : "",
    "entryPoint" : null,
    "parentPlan" : 1571241166731,
    "abstractPlans" : [ ],
    "variableBindings" : [ ],
    "outTransitions" : [ 1573054078777 ],
    "inTransitions" : [ 1573054023369 ]
  } ],
  "transitions" : [ {
    "id" : 1573054018526,
    "name" : "FromDriveToLabToDriveToHallway",
    "comment" : "MISSING_COMMENT",
    "inState" : 1571241667090,
    "outState" : 1571241667604,
    "preCondition" : null,
    "synchronisation" : null
  }, {
    "id" : 1573054021223,
    "name" : "FromDriveToHallwayToDriveToOffices",
    "comment" : "MISSING_COMMENT",
    "inState" : 1571241667604,
    "outState" : 1571241671453,
    "preCondition" : null,
    "synchronisation" : null
  }, {
    "id" : 1573054023369,
    "name" : "FromDriveToOfficesToDriveToKitchen",
    "comment" : "MISSING_COMMENT",
    "inState" : 1571241671453,
    "outState" : 1571241672784,
    "preCondition" : null,
    "synchronisation" : null
  }, {
    "id" : 1573054078777,
    "name" : "FromDriveToKitchenToDriveToLab",
    "comment" : "MISSING_COMMENT",
    "inState" : 1571241672784,
    "outState" : 1571241667090,
    "preCondition" : null,
    "synchronisation" : null
  } ],
  "synchronisations" : [ ]
}