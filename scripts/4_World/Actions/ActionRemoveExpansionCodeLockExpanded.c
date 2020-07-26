class ActionRemoveExpansionCodeLockExpandedCB : ActionContinuousBaseCB {
    override void CreateActionComponent() {
<<<<<<< HEAD
		float circleTime = 10; 
=======
	float circleTime = 15; 
>>>>>>> dbcd7fdd7f049fdd0edf64bf2bd7e7fc89d7ffba
      	m_ActionData.m_ActionComponent = new CAContinuousRepeat(circleTime);
    }
}

class ActionRemoveExpansionCodeLockExpanded : ActionContinuousBase {

    void ActionRemoveExpansionCodeLockExpanded() {
        m_CallbackClass = ActionRemoveExpansionCodeLockExpandedCB;
        m_CommandUID = DayZPlayerConstants.CMD_ACTIONFB_INTERACT;
        m_StanceMask = DayZPlayerConstants.STANCEMASK_ERECT;
        m_FullBody = true;
    }

    override void CreateConditionComponents() {
        m_ConditionItem = new CCINonRuined();
        m_ConditionTarget = new CCTNone();
    }

    override string GetText() {
        return "Remove Codelock";
    }

    override bool ActionCondition(PlayerBase player, ActionTarget target, ItemBase item) {
<<<<<<< HEAD
		ItemBase m_TargetItem;
		if (TentBase.Cast(target.GetParent())){
			m_TargetItem = ItemBase.Cast(target.GetParent());
		} else {
			m_TargetItem = ItemBase.Cast(target.GetObject());
		}
		
		ExpansionCarAdminKey key = ExpansionCarAdminKey.Cast(item);
	

		if (m_TargetItem && key) {
			if (m_TargetItem.IsLocked() || ExpansionCodeLock.Cast(m_TargetItem.GetAttachmentByConfigTypeName("ExpansionCodeLock")) || m_TargetItem.HasCode()) {
					return true;
				}
	    }
		return false;
    }

    override void OnFinishProgressServer(ActionData action_data) {
        ItemBase m_TargetItem;
		if (TentBase.Cast(action_data.m_Target.GetParent())){
			m_TargetItem = ItemBase.Cast(action_data.m_Target.GetParent());
		} else {
			m_TargetItem = ItemBase.Cast(action_data.m_Target.GetObject());
		}

		PlayerBase player = PlayerBase.Cast(action_data.m_Player);
		
		if (m_TargetItem && player){
			if (GetExpansionCodeLockConfig().ScriptLogging){
				Print("[CodeLockExpanded][Admin] " + player.GetIdentity().GetName() + "(" +  player.GetIdentity().GetPlainId() +") Removed Code Lock from " + m_TargetItem.GetType() + " at " + m_TargetItem.GetPosition());
			}
			m_TargetItem.Unlock();
			m_TargetItem.SetCode("");
			ExpansionCodeLock codelock = ExpansionCodeLock.Cast(m_TargetItem.GetAttachmentByConfigTypeName( "ExpansionCodeLock" ));
			if ( codelock ){
				m_TargetItem.GetInventory().DropEntity(InventoryMode.SERVER, m_TargetItem, codelock);
			}
		}
=======
		ItemBase itemParent = ItemBase.Cast(target.GetParent());
		ExpansionCarAdminKey key = ExpansionCarAdminKey.Cast(item);
	
	        if (itemParent && key) {
			if (itemParent.IsLocked() || ExpansionCodeLock.Cast(itemParent.FindAttachmentBySlotName( "Att_ExpansionCodeLock" )) || itemParent.HasCode()) {
				return true;
			}
		}
    }

    override void OnFinishProgressServer(ActionData action_data) {
        ItemBase itemParent = ItemBase.Cast(action_data.m_Target.GetParent());
	itemParent.Unlock();
	itemParent.SetCode("");
	ExpansionCodeLock codelock = ExpansionCodeLock.Cast(itemParent.FindAttachmentBySlotName( "Att_ExpansionCodeLock" ));
	if(codelock){
		itemParent.GetInventory().DropEntity(InventoryMode.SERVER, itemParent, codelock);
	}
>>>>>>> dbcd7fdd7f049fdd0edf64bf2bd7e7fc89d7ffba
    }
}
